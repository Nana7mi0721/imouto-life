
undefined4 FUN_0064df80(int param_1,uint param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  uint local_460;
  undefined1 local_45c [16];
  undefined4 local_44c;
  uint local_448;
  uint local_408;
  undefined4 local_404;
  undefined1 local_400;
  undefined4 local_3ff;
  
  local_400 = DAT_00f3fa48;
  puVar3 = &local_3ff;
  for (iVar2 = 0xff; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  *(undefined2 *)puVar3 = 0;
  *(undefined1 *)((int)puVar3 + 2) = 0;
  iVar2 = FUN_006507c0(param_1);
  if (iVar2 != 0) {
    uVar1 = FUN_006507b0(param_1,s_Can_t_use_TIFFReadRGBAStrip___wi_00a06730);
    FUN_006512e0(*(undefined4 *)(param_1 + 0x274),uVar1);
    return 0;
  }
  FUN_00651280(param_1,0x116,&local_460);
  if (param_2 % local_460 != 0) {
    uVar1 = FUN_006507b0(param_1,s_Row_passed_to_TIFFReadRGBAStrip__00a066f4);
    FUN_006512e0(*(undefined4 *)(param_1 + 0x274),uVar1);
    return 0;
  }
  iVar2 = FUN_00646d50(param_1,&local_400);
  if ((iVar2 == 0) || (iVar2 = FUN_006470f0(local_45c,param_1,0,&local_400), iVar2 == 0)) {
    uVar1 = FUN_006507b0(param_1,&DAT_00a06554,&local_400);
    FUN_006512e0(*(undefined4 *)(param_1 + 0x274),uVar1);
    return 0;
  }
  local_408 = param_2;
  local_404 = 0;
  if (local_448 < local_460 + param_2) {
    local_460 = local_448 - param_2;
  }
  uVar1 = FUN_006476d0(local_45c,param_3,local_44c,local_460);
  FUN_00647030(local_45c);
  return uVar1;
}

