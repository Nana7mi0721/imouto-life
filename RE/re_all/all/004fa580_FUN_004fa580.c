
undefined4 FUN_004fa580(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0xffffff9a;
  }
  else {
    local_14 = *param_2;
    local_10 = 0;
    local_c = param_2[1];
    local_8 = 0;
    uVar1 = FUN_004fa4f0(param_1,&local_14);
  }
  return uVar1;
}

