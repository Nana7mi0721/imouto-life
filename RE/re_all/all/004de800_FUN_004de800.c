
void __fastcall FUN_004de800(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  char *pcVar3;
  
  uVar2 = *(undefined4 *)(param_1 + 4);
  puVar1 = (undefined4 *)FUN_004e1fc0(uVar2);
  uVar2 = FUN_004e8480(*puVar1,uVar2);
  puVar1 = (undefined4 *)FUN_004e1fc0();
  *puVar1 = uVar2;
  uVar2 = FUN_004cc130();
  *(undefined4 *)(param_1 + 8) = uVar2;
  puVar1 = (undefined4 *)FUN_004e1fc0();
  pcVar3 = (char *)FUN_004d6860(*puVar1);
  if (*pcVar3 == '\0') {
    puVar1 = (undefined4 *)FUN_004e1fc0();
    uVar2 = FUN_004e8a70(*puVar1);
    puVar1 = (undefined4 *)FUN_004e1f00();
    *puVar1 = uVar2;
    puVar1 = (undefined4 *)FUN_004e1fc0();
    uVar2 = FUN_004e8a30(*puVar1);
    puVar1 = (undefined4 *)FUN_004e1fa0();
    *puVar1 = uVar2;
  }
  else {
    puVar1 = (undefined4 *)FUN_004e1f00();
    *puVar1 = *(undefined4 *)(param_1 + 4);
    puVar1 = (undefined4 *)FUN_004e1fa0();
    *puVar1 = *(undefined4 *)(param_1 + 4);
  }
  return;
}

