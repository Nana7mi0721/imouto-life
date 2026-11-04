
uint FUN_006be360(undefined4 param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  int iVar4;
  
  iVar1 = FUN_006be4c0(param_1);
  iVar4 = 0;
  if (-1 < iVar1) {
    iVar2 = FUN_006bf140(param_1);
    if (iVar1 <= iVar2) {
      pvVar3 = _malloc(iVar1 + 1);
      param_2[3] = (int)pvVar3;
      if (pvVar3 == (void *)0x0) {
        return 0xffffffff;
      }
      FUN_006be1b0(param_1,pvVar3,iVar1);
      *(undefined1 *)(param_2[3] + iVar1) = 0;
      iVar1 = FUN_006be4c0(param_1);
      param_2[2] = iVar1;
      if ((-1 < iVar1) && (iVar1 < 0x20000000)) {
        iVar2 = FUN_006bf140(param_1);
        if (iVar1 * 4 <= iVar2) {
          pvVar3 = _malloc(param_2[2] << 2);
          param_2[1] = (int)pvVar3;
          pvVar3 = _malloc(param_2[2] << 2);
          *param_2 = (int)pvVar3;
          if ((param_2[1] == 0) || (pvVar3 == (void *)0x0)) {
LAB_006be499:
            param_2[2] = iVar4;
            return 0xffffffff;
          }
          if (0 < param_2[2]) {
            do {
              iVar1 = FUN_006be4c0(param_1);
              if (iVar1 < 0) goto LAB_006be4a4;
              iVar2 = FUN_006bf140(param_1);
              if (iVar2 < iVar1) goto LAB_006be4a4;
              *(int *)(param_2[1] + iVar4 * 4) = iVar1;
              pvVar3 = _malloc(iVar1 + 1);
              *(void **)(*param_2 + iVar4 * 4) = pvVar3;
              iVar2 = *(int *)(*param_2 + iVar4 * 4);
              if (iVar2 == 0) goto LAB_006be499;
              FUN_006be1b0(param_1,iVar2,iVar1);
              iVar2 = iVar4 * 4;
              iVar4 = iVar4 + 1;
              *(undefined1 *)(*(int *)(*param_2 + iVar2) + iVar1) = 0;
            } while (iVar4 < param_2[2]);
          }
          iVar1 = FUN_006bf140(param_1);
          return (-1 < iVar1) - 1 & 0xffffffec;
        }
      }
LAB_006be4a4:
      param_2[2] = iVar4;
    }
  }
  return 0xffffffec;
}

