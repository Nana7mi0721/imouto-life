
void __thiscall FUN_004cfd10(int param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined1 local_c [4];
  undefined1 local_8 [4];
  
  uVar1 = FUN_004cfc90();
  uVar2 = FUN_004d9f40();
  if (uVar1 < uVar2) {
    uVar3 = FUN_004da570(*(undefined4 *)(param_1 + 8),1,param_2);
    *(undefined4 *)(param_1 + 8) = uVar3;
  }
  else {
    puVar4 = (undefined4 *)FUN_004e38e0(local_8);
    FUN_004cfd80(local_c,*puVar4,param_2);
  }
  return;
}

