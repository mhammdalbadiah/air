#!/usr/bin/env bash
set -e

PROJECT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
BIN_PATH="$PROJECT_DIR/air"

echo "==> Building project using Make..."
make -C "$PROJECT_DIR"

if [ "$(id -u)" -eq 0 ]; then
    echo "==> Installing globally to /usr/local/bin..."
    install -m 755 "$BIN_PATH" /usr/local/bin/air
    echo "==> Installed to /usr/local/bin/air"
    exit 0
fi

if command -v sudo >/dev/null 2>&1; then
    echo "==> Installing globally to /usr/local/bin (requires sudo)..."
    if sudo install -m 755 "$BIN_PATH" /usr/local/bin/air; then
        echo "==> Installed to /usr/local/bin/air"
        exit 0
    else
        echo "==> Sudo failed or cancelled. Falling back to local shell setup..."
    fi
fi

if [ -d "$HOME/.config/fish" ] || [ -n "$FISH_VERSION" ]; then
    FISH_FUNC_DIR="$HOME/.config/fish/functions"
    mkdir -p "$FISH_FUNC_DIR"
    cat <<EOF > "$FISH_FUNC_DIR/air.fish"
function air
    $BIN_PATH \$argv
end
EOF
    echo "==> Added fish function to $FISH_FUNC_DIR/air.fish"
fi

USER_BIN="$HOME/.local/bin"
mkdir -p "$USER_BIN"
ln -sf "$BIN_PATH" "$USER_BIN/air"
echo "==> Linked binary to $USER_BIN/air"

if [[ ":$PATH:" != *":$USER_BIN:"* ]]; then
    echo "==> Note: Make sure $USER_BIN is in your PATH."
fi

echo "==> Installation complete! You can now run 'air', 'air -tui', or 'air -gui'."