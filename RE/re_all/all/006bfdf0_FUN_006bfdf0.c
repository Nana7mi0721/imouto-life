
void FUN_006bfdf0(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_4;
  
  local_4 = 5;
  do {
    iVar5 = local_4 / 3;
    iVar6 = local_4 % 3;
    if (0 < local_4) {
      iVar3 = (local_4 + -1) / 3;
      iVar7 = (local_4 + -1) % 3;
      piVar1 = (int *)(param_1 + (iVar6 + (iVar5 + 9) * 3) * 0xc);
      if (*piVar1 == *(int *)(param_1 + (iVar7 + (iVar3 + 9) * 3) * 0xc)) {
        *piVar1 = 0;
      }
      iVar2 = iVar6 + iVar5 * 3;
      if (*(int *)(param_1 + 0x148 + iVar2 * 0xc) ==
          *(int *)(param_1 + 0x148 + (iVar7 + iVar3 * 3) * 0xc)) {
        *(undefined4 *)(param_1 + 0x148 + iVar2 * 0xc) = 0;
      }
    }
    if (0 < iVar5) {
      iVar3 = iVar6 * 3 + 0x5a;
      if (*(int *)(param_1 + iVar3 * 4) == *(int *)(param_1 + (iVar6 * 3 + 0x51) * 4)) {
        *(undefined4 *)(param_1 + iVar3 * 4) = 0;
      }
      if (*(int *)(param_1 + 0x16c + iVar6 * 0xc) == *(int *)(param_1 + 0x148 + iVar6 * 0xc)) {
        *(undefined4 *)(param_1 + iVar6 * 0xc + 0x16c) = 0;
      }
    }
    _free(*(void **)(param_1 + (iVar6 + (iVar5 + 9) * 3) * 0xc));
    _free(*(void **)(param_1 + 0x148 + (iVar6 + iVar5 * 3) * 0xc));
    bVar4 = 0 < local_4;
    local_4 = local_4 + -1;
  } while (bVar4);
  return;
}

