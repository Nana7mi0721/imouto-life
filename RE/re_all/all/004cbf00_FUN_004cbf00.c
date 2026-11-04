
void __fastcall FUN_004cbf00(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_004e1fc0();
  FUN_004d5920(*puVar1);
  puVar1 = (undefined4 *)FUN_004e1fc0();
  *puVar1 = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(param_1 + 8) = 0;
  puVar1 = (undefined4 *)FUN_004e1f00();
  *puVar1 = *(undefined4 *)(param_1 + 4);
  puVar1 = (undefined4 *)FUN_004e1fa0();
  *puVar1 = *(undefined4 *)(param_1 + 4);
  return;
}

