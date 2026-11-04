
undefined4 FUN_00401a10(undefined4 param_1,FILE *param_2,long param_3,int param_4)

{
  int iVar1;
  undefined4 local_c;
  int local_8;
  
  if (param_4 == 0) {
    local_8 = 0;
  }
  else if (param_4 == 1) {
    local_8 = 1;
  }
  else {
    if (param_4 != 2) {
      return 0xffffffff;
    }
    local_8 = 2;
  }
  local_c = 0;
  iVar1 = _fseek(param_2,param_3,local_8);
  if (iVar1 != 0) {
    local_c = 0xffffffff;
  }
  return local_c;
}

