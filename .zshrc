# Check if code-insiders is installed
if command -v code-insiders &> /dev/null; then
  alias code="code-insiders"
fi

# Define the code function
function code() {
  command code "$@"
}
