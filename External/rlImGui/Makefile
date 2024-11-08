# Alternative GNU Make workspace makefile autogenerated by Premake

ifndef config
  config=debug_x64
endif

ifndef verbose
  SILENT = @
endif

ifeq ($(config),debug_x64)
  raylib_config = debug_x64
  rlImGui_config = debug_x64
  simple_config = debug_x64
  editor_config = debug_x64
  imgui_style_example_config = debug_x64
  docking_example_config = debug_x64
  asset_browser_config = debug_x64

else ifeq ($(config),release_x64)
  raylib_config = release_x64
  rlImGui_config = release_x64
  simple_config = release_x64
  editor_config = release_x64
  imgui_style_example_config = release_x64
  docking_example_config = release_x64
  asset_browser_config = release_x64

else
  $(error "invalid configuration $(config)")
endif

PROJECTS := raylib rlImGui simple editor imgui_style_example docking_example asset_browser

.PHONY: all clean help $(PROJECTS) Examples

all: $(PROJECTS)

Examples: asset_browser docking_example editor imgui_style_example simple

raylib:
ifneq (,$(raylib_config))
	@echo "==== Building raylib ($(raylib_config)) ===="
	@${MAKE} --no-print-directory -C build -f raylib.make config=$(raylib_config)
endif

rlImGui:
ifneq (,$(rlImGui_config))
	@echo "==== Building rlImGui ($(rlImGui_config)) ===="
	@${MAKE} --no-print-directory -C build -f rlImGui.make config=$(rlImGui_config)
endif

simple: raylib rlImGui
ifneq (,$(simple_config))
	@echo "==== Building simple ($(simple_config)) ===="
	@${MAKE} --no-print-directory -C build -f simple.make config=$(simple_config)
endif

editor: raylib rlImGui
ifneq (,$(editor_config))
	@echo "==== Building editor ($(editor_config)) ===="
	@${MAKE} --no-print-directory -C build -f editor.make config=$(editor_config)
endif

imgui_style_example: raylib rlImGui
ifneq (,$(imgui_style_example_config))
	@echo "==== Building imgui_style_example ($(imgui_style_example_config)) ===="
	@${MAKE} --no-print-directory -C build -f imgui_style_example.make config=$(imgui_style_example_config)
endif

docking_example: raylib rlImGui
ifneq (,$(docking_example_config))
	@echo "==== Building docking_example ($(docking_example_config)) ===="
	@${MAKE} --no-print-directory -C build -f docking_example.make config=$(docking_example_config)
endif

asset_browser: raylib rlImGui
ifneq (,$(asset_browser_config))
	@echo "==== Building asset_browser ($(asset_browser_config)) ===="
	@${MAKE} --no-print-directory -C build -f asset_browser.make config=$(asset_browser_config)
endif

clean:
	@${MAKE} --no-print-directory -C build -f raylib.make clean
	@${MAKE} --no-print-directory -C build -f rlImGui.make clean
	@${MAKE} --no-print-directory -C build -f simple.make clean
	@${MAKE} --no-print-directory -C build -f editor.make clean
	@${MAKE} --no-print-directory -C build -f imgui_style_example.make clean
	@${MAKE} --no-print-directory -C build -f docking_example.make clean
	@${MAKE} --no-print-directory -C build -f asset_browser.make clean

help:
	@echo "Usage: make [config=name] [target]"
	@echo ""
	@echo "CONFIGURATIONS:"
	@echo "  debug_x64"
	@echo "  release_x64"
	@echo ""
	@echo "TARGETS:"
	@echo "   all (default)"
	@echo "   clean"
	@echo "   raylib"
	@echo "   rlImGui"
	@echo "   simple"
	@echo "   editor"
	@echo "   imgui_style_example"
	@echo "   docking_example"
	@echo "   asset_browser"
	@echo ""
	@echo "For more information, see https://github.com/premake/premake-core/wiki"