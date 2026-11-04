
undefined4
FUN_00401bd0(undefined4 param_1,FILE *param_2,long param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  undefined4 local_c;
  int local_8;
  
  if (param_5 == 0) {
    local_8 = 0;
  }
  else if (param_5 == 1) {
    local_8 = 1;
  }
  else {
    if (param_5 != 2) {
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

