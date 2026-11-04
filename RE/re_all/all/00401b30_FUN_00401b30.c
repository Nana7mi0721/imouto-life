
FILE * FUN_00401b30(undefined4 param_1,char *param_2,uint param_3)

{
  undefined **local_c;
  FILE *local_8;
  
  local_8 = (FILE *)0x0;
  local_c = (undefined **)0x0;
  if ((param_3 & 3) == 1) {
    local_c = (undefined **)&DAT_0084b20c;
  }
  else if ((param_3 & 4) == 0) {
    if ((param_3 & 8) != 0) {
      local_c = (undefined **)&DAT_0084b214;
    }
  }
  else {
    local_c = &PTR_LAB_00622b6e_4_0084b210;
  }
  if ((param_2 != (char *)0x0) && (local_c != (undefined **)0x0)) {
    local_8 = _fopen(param_2,(char *)local_c);
  }
  return local_8;
}

