
void FUN_004f96a0(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_30 [9];
  undefined4 local_c;
  undefined4 local_8;
  
  if (param_2 == (undefined4 *)0x0) {
    FUN_004f87b0(param_1,0,1);
  }
  else {
    puVar2 = local_30;
    for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = *param_2;
      param_2 = param_2 + 1;
      puVar2 = puVar2 + 1;
    }
    local_c = 0;
    local_8 = 0;
    FUN_004f87b0(param_1,local_30,1);
  }
  return;
}

