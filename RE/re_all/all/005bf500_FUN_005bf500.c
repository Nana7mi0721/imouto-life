
undefined4 FUN_005bf500(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int local_4;
  
  if (*(char *)(param_1 + 8) != '\0') {
    piVar2 = (int *)(param_1 + 0x3c);
    local_4 = 0;
    if (0 < *(int *)(param_1 + 0x38)) {
      do {
        if (*(int *)(*piVar2 + 0xc) != 0) {
          iVar1 = ((-(uint)(*(char *)(param_1 + 9) != '\0') & 5) + 1) * *(int *)(param_1 + 0x34);
          iVar3 = 0;
          if (0 < iVar1) {
            do {
              if (*(int *)(*(int *)(*piVar2 + 0xc) + iVar3 * 4) != 0) {
                FUN_005d1f40(*(undefined4 *)(*(int *)(*piVar2 + 0xc) + iVar3 * 4));
                *(undefined4 *)(*(int *)(*piVar2 + 0xc) + iVar3 * 4) = 0;
              }
              iVar3 = iVar3 + 1;
            } while (iVar3 < iVar1);
          }
          FUN_0056e1d0(*(undefined4 *)(*piVar2 + 0xc));
          *(undefined4 *)(*piVar2 + 0xc) = 0;
        }
        if (*(int *)(*piVar2 + 8) != 0) {
          FUN_005bf410(*(int *)(*piVar2 + 8));
          *(undefined4 *)(*piVar2 + 8) = 0;
        }
        if (*(int *)*piVar2 != 0) {
          FUN_005d1ee0(*(int *)*piVar2);
          *(undefined4 *)*piVar2 = 0;
        }
        if (*(int *)(*piVar2 + 4) != 0) {
          FUN_005d1ee0(*(int *)(*piVar2 + 4));
          *(undefined4 *)(*piVar2 + 4) = 0;
        }
        if (*(int *)(*piVar2 + 0x14) != 0) {
          iVar1 = 0;
          if (0 < *(int *)(param_1 + 0x34)) {
            do {
              if (*(int *)(*(int *)(*piVar2 + 0x14) + iVar1 * 4) != 0) {
                FUN_005d1f60(*(undefined4 *)(*(int *)(*piVar2 + 0x14) + iVar1 * 4));
                *(undefined4 *)(*(int *)(*piVar2 + 0x14) + iVar1 * 4) = 0;
              }
              iVar1 = iVar1 + 1;
            } while (iVar1 < *(int *)(param_1 + 0x34));
          }
          FUN_0056e1d0(*(undefined4 *)(*piVar2 + 0x14));
          *(undefined4 *)(*piVar2 + 0x14) = 0;
        }
        if (*(int *)(*piVar2 + 0x10) != 0) {
          FUN_005d1ee0(*(int *)(*piVar2 + 0x10));
          *(undefined4 *)(*piVar2 + 0x10) = 0;
        }
        local_4 = local_4 + 1;
        piVar2 = piVar2 + 7;
      } while (local_4 < *(int *)(param_1 + 0x38));
    }
  }
  return 0;
}

