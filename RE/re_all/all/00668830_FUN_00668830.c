
void FUN_00668830(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  undefined1 *puVar2;
  undefined1 local_res0;
  undefined1 local_18 [24];
  
  uVar1 = param_4;
  if ((int)param_4 < 0) {
    uVar1 = ~param_4 + 1;
  }
  puVar2 = (undefined1 *)FUN_00668690(local_18,&local_res0,param_3,uVar1);
  if (((int)param_4 < 0) && (local_18 < puVar2)) {
    puVar2 = puVar2 + -1;
    *puVar2 = 0x2d;
  }
  FUN_00668800(param_1,param_2,puVar2);
  return;
}

