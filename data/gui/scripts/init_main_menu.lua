-- CEGUI Singletons
local logger = CEGUI.Logger:getSingleton()
local system = CEGUI.System:getSingleton()
local winman = CEGUI.WindowManager:getSingleton()
local animan = CEGUI.AnimationManager:getSingleton()
-- Init Main Menu Begin
logger:logEvent("++++ Main Menu Init Begin ++++")
-- Load additional imageset
CEGUI.ImagesetManager:getSingleton():create("LibLogos.imageset")
-- Load the layout
local layout = winman:loadWindowLayout("main_menu.layout")
-- Set as layout
system:setGUISheet(layout);
-- Connection progress animation
local serverConnectProgress = winman:getWindow("MainMenu/ServerWaiting/Progress")
local clientConnectProgress = winman:getWindow("MainMenu/ClientWaiting/Progress")
animan:loadAnimationsFromXML("main_menu.anim")
local animinsServer = animan:instantiateAnimation("ConnectionProgress")
local animinsClient = animan:instantiateAnimation("ConnectionProgress")
animinsServer:setTargetWindow(serverConnectProgress)
animinsServer:start()
animinsClient:setTargetWindow(clientConnectProgress)
animinsClient:start()
-- Init Main Menu End
logger:logEvent("++++ Main Menu Init Completed ++++")
--*** Functions for gui behavior ***--
-- Submenu enter
function submenu_enter(from, to)
	winman:getWindow(from):disable()
	winman:getWindow(to):show()
	winman:getWindow(to):activate()
end
-- Submenu leave
function submenu_leave(from, to)
	winman:getWindow(from):hide()
	winman:getWindow(to):enable()
end
-- Enter to a submenu
function mainmenu_submenu_enter(from, to)
	submenu_enter("MainMenu/"..from, "MainMenu/"..to)
end
-- Leave a submenu
function mainmenu_submenu_leave(from, to)
	submenu_leave("MainMenu/"..from, "MainMenu/"..to)
end
-- Credits Button
function mainmenu_credits_clicked(arg)
	logger:logEvent( ">>> Credits shows" )
	mainmenu_submenu_enter("Menu", "Credits")
end
-- Credits Exit Button
function mainmenu_credits_exit_clicked(arg)
	logger:logEvent( ">>> Credits hides" )
	mainmenu_submenu_leave("Credits", "Menu")
end
-- Multi show
function mainmenu_multi_show(arg)
	logger:logEvent( ">>> Multi shows" )
	mainmenu_submenu_enter("Menu", "MultiTab")
end
-- Multi hide
function mainmenu_multi_hide(arg)
	logger:logEvent( ">>> Multi hide" )
	mainmenu_submenu_leave("MultiTab", "Menu")
end
-- Multi Server Start Button
function mainmenu_server_start_clicked(arg)
	logger:logEvent( ">>> Server Starts" )
	mainmenu_submenu_enter("MultiTab", "ServerWaiting")
end
-- Multi Server Cancel Button
function mainmenu_server_cancel_clicked(arg)
	logger:logEvent(">>> Server Canceled" )
	mainmenu_submenu_leave("ServerWaiting","MultiTab")
end
-- Multi Client Start Button
function mainmenu_client_start_clicked(arg)
	logger:logEvent( ">>> Client Starts" )
	mainmenu_submenu_enter("MultiTab", "ClientWaiting")
end
-- Multi Client Cancel Button
function mainmenu_client_cancel_clicked(arg)
	logger:logEvent(">>> Server Canceled" )
	mainmenu_submenu_leave("ClientWaiting","MultiTab")
end
