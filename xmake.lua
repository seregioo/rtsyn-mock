local project_name = "rtsyn-mock"
local project_xmake_repo = "rtsyn-xmake-repo"

set_license("GPL-3.0-or-later")

add_rules("mode.debug", "mode.release")
add_rules("plugin.compile_commands.autoupdate")

option("valgrind", { default = false, description = "Run tests with Valgrind" })

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

target(project_name)
set_kind("shared")
add_files("src/**/*.c")
add_includedirs("include", { public = true })
for i, rtsyn_dependency in ipairs(rtsyn_dependencies) do
	add_packages(rtsyn_dependency)
end
add_includedirs("src")
add_headerfiles("include/(rtsyn/**.h)")

--
-- If you want to known more usage about xmake, please see https://xmake.io
--
