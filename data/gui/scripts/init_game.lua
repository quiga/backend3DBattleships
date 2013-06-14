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
-- Connection progress animation
local menu = winman:getWindow("Game/Menu")
animan:loadAnimationsFromXML("game.anim")
local animinsHover = animan:instantiateAnimation("GameMenuHover")
local animinsLeave = animan:instantiateAnimation("GameMenuLeave")
animinsHover:setTargetWindow(menu)
animinsLeave:setTargetWindow(menu)
-- Init Main Menu End
logger:logEvent("++++ Game Init Completed ++++")