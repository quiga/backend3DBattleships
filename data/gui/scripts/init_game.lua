-- CEGUI Singletons
local logger = CEGUI.Logger:getSingleton()
local system = CEGUI.System:getSingleton()
local winman = CEGUI.WindowManager:getSingleton()
local animan = CEGUI.AnimationManager:getSingleton()
-- Init Main Menu Begin
logger:logEvent("++++ Game Init Begin ++++")
-- Load the layout
local layout = winman:loadWindowLayout("game_hud.layout")
-- Set as layout
system:setGUISheet(layout);
-- Init Main Menu End
logger:logEvent("++++ Game Init Completed ++++")