local project_name = "rtsyn-mock"
local project_xmake_repo = "rtsyn-xmake-repo"

set_license("GPL-3.0-or-later")

add_rules("mode.debug", "mode.release")
add_rules("plugin.compile_commands.autoupdate")
set_defaultmode("release")
if is_mode("release") then
	set_optimize("fastest")
	set_strip("all")
	set_symbols("hidden")
end

option("valgrind", { default = false, description = "Run tests with Valgrind" })
option("tests", { default = true, description = "Build tests" })

set_languages("c23")

local rtsyn_dependencies = { "rtsyn-abi" }
for i, rtsyn_dependency in ipairs(rtsyn_dependencies) do
	add_requires(rtsyn_dependency)
end

local workspace = os.getenv("RTSYN_WORKSPACE")
if workspace then
	local repository_dir = path.join(workspace, project_xmake_repo)
	add_repositories(project_xmake_repo .. " " .. repository_dir)
else
	add_repositories(project_xmake_repo .. " https://github.com/seregioo/" .. project_xmake_repo .. ".git")
end

local function rtsyn_mock_target(name, source)
	target(name)
	set_kind("shared")
	add_files(source)
	add_includedirs("include", { public = true })
	for i, rtsyn_dependency in ipairs(rtsyn_dependencies) do
		add_packages(rtsyn_dependency)
	end
	add_includedirs("src")
	add_headerfiles("include/(rtsyn/**.h)")
end

rtsyn_mock_target(project_name, "src/module_loader/plugin.c")
rtsyn_mock_target(project_name .. "-device", "src/module_loader/device.c")

--
-- If you want to known more usage about xmake, please see https://xmake.io
--
