# 删除指定目录下指定后缀的文件
import os
import shutil


def move_files_by_extension(source_folder, target_folder, extension):
    """
    Moves files with a specified extension from the source folder to the target folder.

    :param source_folder: The folder where the files are located.
    :param target_folder: The folder where the files will be moved.
    :param extension: The file extension to filter files (e.g., ".txt").
    """
    if not os.path.exists(source_folder):
        print(f"Source folder '{source_folder}' does not exist.")
        return

    if not os.path.exists(target_folder):
        print(f"Target folder '{target_folder}' does not exist. Creating it...")
        os.makedirs(target_folder)

    moved_files = 0
    for filename in os.listdir(source_folder):
        if filename.endswith(extension):
            source_file = os.path.join(source_folder, filename)
            target_file = os.path.join(target_folder, filename)

            shutil.move(source_file, target_file)
            print(f"Moved: {filename}")
            moved_files += 1

    if moved_files:
        print(
            f"Successfully moved {moved_files} '{extension}' files to '{target_folder}'."
        )
    else:
        print(f"No '{extension}' files found in '{source_folder}'.")


def main():
    source_folder = input("Enter the source folder path: ")
    target_folder = input("Enter the target folder path: ")
    extension = input("Enter the file extension to move (e.g., '.txt'): ")

    move_files_by_extension(source_folder, target_folder, extension)


# Run the script
if __name__ == "__main__":
    main()
