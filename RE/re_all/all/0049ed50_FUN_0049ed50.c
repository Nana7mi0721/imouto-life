
void __fastcall FUN_0049ed50(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int local_8;
  
  uVar1 = FUN_004d3180();
  *(undefined4 *)(param_1 + 0x10) = uVar1;
  if (0 < *(int *)(param_1 + 0x10)) {
    for (local_8 = 0; local_8 < 0x1f; local_8 = local_8 + 1) {
      iVar2 = (local_8 + 1) * *(int *)(param_1 + 0x10);
      iVar2 = FUN_004d31e0((int)(iVar2 + (iVar2 >> 0x1f & 0x1fU)) >> 5);
      *(undefined4 *)(param_1 + 0x14 + local_8 * 4) = *(undefined4 *)(iVar2 + 0x26c);
    }
  }
  return;
}

