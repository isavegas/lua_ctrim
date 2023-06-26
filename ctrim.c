#include <ctype.h>
#include <lauxlib.h>
#include <lua.h>
#include <stddef.h>
#include <string.h>

int ctrim(lua_State *state) {
  size_t length = 0;
  const char *start = luaL_checklstring(state, 1, &length);
  const char *end = &start[length - 1];

  if (lua_gettop(state) > 1) {
    const char *trim_chars = luaL_checkstring(state, 2);
    while (length && strchr(trim_chars, *start)) {
      start++;
      length--;
    }
    while (length && strchr(trim_chars, *end)) {
      end--;
      length--;
    }
  } else {
    while (length && isspace(*start)) {
      start++;
      length--;
    }
    while (length && isspace(*end)) {
      end--;
      length--;
    }
  }
  lua_pushlstring(state, start, (size_t)(end - start) + 1);
  return 1;
}

int luaopen_ctrim(lua_State *state) {
  lua_pushcfunction(state, ctrim);
  return 1;
}
