-- CEGUI Singletons
local logger = CEGUI.Logger:getSingleton()
local system = CEGUI.System:getSingleton()
local winman = CEGUI.WindowManager:getSingleton()
local animan = CEGUI.AnimationManager:getSingleton()
-- Init Main Menu Begin
logger:logEvent("++++ Main Menu Shut Down Begin ++++")
-- Crear gui
system:setGUISheet(nil);
-- Destroy windows
winman:destroyAllWindows()
-- Crear animation
animan:destroyAnimation("ConnectionProgress")
-- Init Main Menu End
logger:logEvent("++++ Main Menu Shut Down Completed ++++")
