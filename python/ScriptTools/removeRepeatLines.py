# 删除一个文件中的空白行
def remove_duplicate_urls(file_path):
    """
    Detects duplicate URLs in a text file, lists them for user confirmation,
    and removes them if the user agrees.

    :param file_path: Path to the text file containing URLs.
    """
    try:
        # Read all lines from the file
        with open(file_path, "r", encoding="utf-8") as file:
            lines = file.readlines()

        # Track seen URLs and duplicates
        seen = set()
        duplicates = []

        # Identify duplicates
        for line in lines:
            url = line.strip()  # Remove leading/trailing whitespace and newlines
            if url in seen:
                duplicates.append(line)  # Keep the line including the newline
            else:
                seen.add(url)

        # If no duplicates, exit
        if not duplicates:
            print("No duplicate URLs found.")
            return

        # List duplicates for user confirmation
        print("The following duplicate URLs were found:")
        print("".join(duplicates))  # Print all duplicates separated by newlines

        # Ask user for confirmation
        user_input = (
            input("Do you want to delete these duplicates? (y/n): ").strip().lower()
        )
        if user_input != "y":
            print("No changes were made.")
            return

        # Remove duplicates from the lines
        unique_lines = []
        seen = set()
        for line in lines:
            url = line.strip()
            if url not in seen:
                unique_lines.append(line)
                seen.add(url)

        # Write the unique lines back to the file
        with open(file_path, "w", encoding="utf-8") as file:
            file.writelines(unique_lines)

        print("Duplicate URLs have been removed successfully.")

    except FileNotFoundError:
        print(f"Error: The file '{file_path}' was not found.")
    except Exception as e:
        print(f"An error occurred: {e}")


# Run the script
if __name__ == "__main__":
    file_path = input("Enter the path to the text file: ")
    remove_duplicate_urls(file_path)
