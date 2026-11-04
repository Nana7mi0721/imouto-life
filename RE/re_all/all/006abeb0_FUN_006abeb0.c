
undefined4 FUN_006abeb0(int *param_1,int param_2)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = FUN_00797830(param_2,0x20);
  if ((-1 < iVar1) && (iVar1 <= *(int *)(param_2 + 0x10) + -8)) {
    pvVar2 = _calloc(iVar1 + 1,1);
    param_1[3] = (int)pvVar2;
    FUN_006abca0(param_2,pvVar2,iVar1);
    iVar1 = FUN_00797830(param_2,0x20);
    if (-1 < iVar1) {
      iVar3 = FUN_00797940(param_2);
      if (iVar1 <= *(int *)(param_2 + 0x10) - iVar3 >> 2) {
        param_1[2] = iVar1;
        pvVar2 = _calloc(iVar1 + 1,4);
        *param_1 = (int)pvVar2;
        pvVar2 = _calloc(param_1[2] + 1,4);
        param_1[1] = (int)pvVar2;
        iVar1 = 0;
        if (0 < param_1[2]) {
          do {
            iVar3 = FUN_00797830(param_2,0x20);
            if (iVar3 < 0) goto LAB_006abfad;
            iVar4 = FUN_00797940(param_2);
            if (*(int *)(param_2 + 0x10) - iVar4 < iVar3) goto LAB_006abfad;
            *(int *)(param_1[1] + iVar1 * 4) = iVar3;
            pvVar2 = _calloc(iVar3 + 1,1);
            *(void **)(*param_1 + iVar1 * 4) = pvVar2;
            FUN_006abca0(param_2,*(undefined4 *)(*param_1 + iVar1 * 4),iVar3);
            iVar1 = iVar1 + 1;
          } while (iVar1 < param_1[2]);
        }
        iVar1 = FUN_00797830(param_2,1);
        if (iVar1 == 1) {
          return 0;
        }
      }
    }
  }
LAB_006abfad:
  FUN_006ab9f0(param_1);
  return 0xffffff7b;
}

