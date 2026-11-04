
void __fastcall FUN_004d70b0(int param_1)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  
  uVar1 = FUN_004eb2f0();
  *(undefined4 *)(param_1 + 4) = uVar1;
  puVar2 = (undefined1 *)FUN_004d6860(*(undefined4 *)(param_1 + 4));
  *puVar2 = 1;
  puVar3 = (undefined4 *)FUN_004e1fc0();
  *puVar3 = *(undefined4 *)(param_1 + 4);
  puVar3 = (undefined4 *)FUN_004e1f00();
  *puVar3 = *(undefined4 *)(param_1 + 4);
  puVar3 = (undefined4 *)FUN_004e1fa0();
  *puVar3 = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(param_1 + 8) = 0;
  return;
}

