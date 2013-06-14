-- CEGUI singletons
local logger = CEGUI.Logger:getSingleton()
-- Begin Scripting Init
logger:logEvent("++++ Init scripting ++++")
-- Load Default Font
--CEGUI.FontManager:getSingleton():create("Jura-13.font");
-- Load Default Scheme
CEGUI.SchemeManager:getSingleton():create("TaharezLook.scheme");
-- End Scripting Init
logger:logEvent("++++ Scripting Initialization completed ++++")
