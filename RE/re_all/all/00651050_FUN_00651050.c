
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00651050(int param_1)

{
  int iVar1;
  undefined2 uVar2;
  undefined2 *puVar3;
  int iVar4;
  float10 fVar5;
  int local_14;
  
  *(undefined4 *)(param_1 + 0xa8) = 0;
  *(undefined4 *)(param_1 + 0xa4) = 0;
  *(undefined4 *)(param_1 + 0xa0) = 0;
  if (0x1d < *(ushort *)(param_1 + 0x2c)) {
    return 0;
  }
  iVar4 = 1 << ((byte)*(ushort *)(param_1 + 0x2c) & 0x1f);
  iVar1 = iVar4 * 2;
  puVar3 = (undefined2 *)FUN_006507d0();
  *(undefined2 **)(param_1 + 0xa0) = puVar3;
  if (puVar3 == (undefined2 *)0x0) {
    return 0;
  }
  *puVar3 = 0;
  local_14 = 1;
  if (1 < iVar4) {
    do {
      fVar5 = (float10)FUN_006c51d0();
      FUN_006c5af0((double)(fVar5 * (float10)_DAT_00804a68 + (float10)_DAT_00804a60));
      uVar2 = __ftol();
      *(undefined2 *)(*(int *)(param_1 + 0xa0) + local_14 * 2) = uVar2;
      local_14 = local_14 + 1;
    } while (local_14 < iVar4);
  }
  if ((int)((uint)*(ushort *)(param_1 + 0x3a) - (uint)*(ushort *)(param_1 + 0x74)) < 2) {
    return 1;
  }
  iVar4 = FUN_006507d0();
  *(int *)(param_1 + 0xa4) = iVar4;
  if (iVar4 != 0) {
    FUN_00650840(iVar4,*(undefined4 *)(param_1 + 0xa0),iVar1);
    iVar4 = FUN_006507d0(iVar1);
    *(int *)(param_1 + 0xa8) = iVar4;
    if (iVar4 != 0) {
      FUN_00650840(iVar4,*(undefined4 *)(param_1 + 0xa0),iVar1);
      return 1;
    }
  }
  if (*(int *)(param_1 + 0xa0) != 0) {
    FUN_006507e0();
  }
  if (*(int *)(param_1 + 0xa4) != 0) {
    FUN_006507e0();
  }
  if (*(int *)(param_1 + 0xa8) != 0) {
    FUN_006507e0();
  }
  *(undefined4 *)(param_1 + 0xa8) = 0;
  *(undefined4 *)(param_1 + 0xa4) = 0;
  *(undefined4 *)(param_1 + 0xa0) = 0;
  return 0;
}

