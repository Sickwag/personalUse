# AI generate，在cherry->Script Writing -> 简单python脚本中
import os
import re
import subprocess
import argparse
from pathlib import Path
from collections import defaultdict


class ScriptManager:
    def __init__(self, scripts_dir):
        self.scripts_dir = Path(scripts_dir).expanduser().absolute()
        self.scripts = {}
        self._load_scripts()
        self._resolve_abbreviation_conflicts()

    def _load_scripts(self):
        """Load all Python scripts and generate initial abbreviations"""
        for file in self.scripts_dir.glob("*.py"):
            if file.name == "scripts_manager.py":
                continue

            # Extract first line comment as description
            with open(file, "r", encoding="utf-8") as f:
                first_line = f.readline().strip()
            desc = ""
            if first_line.startswith(("#", '"', "'")):
                desc = first_line.lstrip("#").strip("\"'").strip()

            # Generate smart abbreviation
            self.scripts[str(file.name)] = {
                "path": str(file),
                "description": desc,
                "abbreviation": self._generate_abbreviation(file.name),
                "full_name": file.stem,
            }

    def _generate_abbreviation(self, filename):
        """Generate intelligent abbreviation based on filename"""
        name = Path(filename).stem

        # Rule 1: Take first letter of each word (for camelCase or snake_case)
        parts = re.findall(r"([A-Za-z][a-z]*|[a-z]+)", name)
        abbr = "".join([p[0].lower() for p in parts if p])

        # Rule 2: For single long words, take first 3 letters
        if len(abbr) < 2 and len(name) >= 3:
            abbr = name[:3].lower()

        # Rule 3: Fallback to first 2 consonants
        if len(abbr) < 2:
            consonants = [c for c in name.lower() if c in "bcdfghjklmnpqrstvwxyz"]
            abbr = "".join(consonants[:2]) if consonants else name[:2].lower()

        return abbr

    def _resolve_abbreviation_conflicts(self):
        """Resolve abbreviation conflicts by adding numbers"""
        abbr_map = defaultdict(list)

        # Group scripts by abbreviation
        for name, data in self.scripts.items():
            abbr_map[data["abbreviation"]].append(name)

        # Add numbers to conflicting abbreviations
        for abbr, files in abbr_map.items():
            if len(files) > 1:
                for i, filename in enumerate(files, 1):
                    self.scripts[filename]["abbreviation"] = (
                        f"{abbr}{i}" if i > 1 else abbr
                    )

    def show_menu(self):
        """Display available scripts menu"""
        print("\n🛠️  Available scripts:")
        print("-" * 60)
        for name, data in sorted(self.scripts.items()):
            print(f"{name: <25} ({data['abbreviation']: <5}) - {data['description']}")
        print("-" * 60)
        print("⌨️  Usage: <script_name/abbrev> [args]")
        print("     Type 'exit' or Ctrl+C to quit\n")

    def find_script(self, input_str):
        """Find script by name or abbreviation"""
        input_str = input_str.lower()
        for data in self.scripts.values():
            if (
                input_str == data["abbreviation"].lower()
                or input_str == data["full_name"].lower()
            ):
                return data
        return None

    def run_script(self, script_name, args):
        """Execute the specified script with PowerShell-safe handling"""
        script = self.find_script(script_name)
        if not script:
            print(f"❌ Error: Unknown script '{script_name}'")
            return False
            
        # 处理PowerShell特殊字符
        processed_args = []
        for arg in args:
            if '&' in arg and not arg.startswith('"'):
                processed_args.append(f'"{arg}"')
            else:
                processed_args.append(arg)
        
        cmd = ['python', script['path']] + processed_args
        print(f"\n🚀 Running: {' '.join(cmd)}")
        
        try:
            subprocess.run(cmd, check=True, shell=True)  # 注意添加 shell=True
            return True
        except subprocess.CalledProcessError as e:
            print(f"❌ Script failed with error code {e.returncode}")
            return False


def get_default_scripts_dir():
    """Get platform-appropriate default scripts directory"""
    home = Path.home()
    if os.name == "nt":  # Windows
        return "D:\\Code Files\\vscode\\python\\ScriptTools"
    else:  # Linux/macOS
        return home / "bin"


def create_alias_help():
    """Show alias setup instructions"""
    script_path = Path(__file__).absolute()
    return (
        "\n🔧 First-time setup:\n"
        f"1. Move this file to your scripts directory (e.g. {get_default_scripts_dir()})\n"
        "2. Add this to your shell config (.bashrc/.zshrc):\n\n"
        f"    alias sm='python3 \"{script_path}\"'\n"
        "\n3. Restart your terminal or run: source ~/.bashrc"
    )


def main():
    # Set up argument parser
    parser = argparse.ArgumentParser(
        description="Script Manager - Run your scripts with abbreviated names",
        add_help=False,
    )
    parser.add_argument(
        "command", nargs=argparse.REMAINDER, help="<script_name/abbrev> [args...]"
    )
    parser.add_argument(
        "--dir", default=get_default_scripts_dir(), help="Custom scripts directory"
    )
    parser.add_argument("-h", "--help", action="store_true", help="Show help message")

    args = parser.parse_args()

    if args.help or not args.command:
        print(create_alias_help())

    # Initialize script manager
    try:
        manager = ScriptManager(args.dir)
    except Exception as e:
        print(f"❌ Failed to initialize: {e}")
        print(f"Check that directory exists: {args.dir}")
        return

    # Direct execution mode (sm <script> [args])
    if args.command and not args.help:
        manager.run_script(args.command[0], args.command[1:])
        return

    # Interactive mode
    manager.show_menu()
    while True:
        try:
            user_input = input("sm> ").strip()
            if not user_input:
                continue

            if user_input.lower() in ("exit", "quit"):
                print("👋 Goodbye!")
                break

            parts = user_input.split()
            if not manager.run_script(parts[0], parts[1:]):
                manager.show_menu()

        except KeyboardInterrupt:
            print("\n👋 Goodbye!")
            break
        except Exception as e:
            print(f"❌ Error: {e}")


if __name__ == "__main__":
    main()
