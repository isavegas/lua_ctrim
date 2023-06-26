rockspec_format = "1.1"
package = "ctrim"
version = "1.0-1"
source = {
   url = "https://github.com/isavegas/lua_ctrim"
}
description = {
   homepage = "https://github.com/isavegas/lua_ctrim",
   license = "MIT"
}
dependencies = {
   "lua >= 5.1, < 5.5"
}
build = {
   type = "builtin",
   modules = {
      ctrim = {
         sources = "ctrim.c"
      }
   }
}
