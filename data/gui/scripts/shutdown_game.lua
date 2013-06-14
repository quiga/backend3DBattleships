-- CEGUI Singletons
local logger = CEGUI.Logger:getSingleton()
local system = CEGUI.System:getSingleton()
local winman = CEGUI.WindowManager:getSingleton()
local animan = CEGUI.AnimationManager:getSingleton()
-- Init Main Menu Begin
logger:logEvent("++++ Game Shut Down Begin ++++")
-- Clear gui
system:setGUISheet(nil)
-- Destroy windows
winman:destroyAllWindows()
-- Init Main Menu End
logger:logEvent("++++ Game Shut Down Completed ++++")
