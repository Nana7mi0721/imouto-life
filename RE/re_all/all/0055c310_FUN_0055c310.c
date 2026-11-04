
undefined4 FUN_0055c310(int param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  char cVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x24b8);
  *(int *)(param_1 + 0x24bc) = *(int *)(param_1 + 0x24bc) + 1;
  cVar2 = *(char *)(iVar3 * 0x4a0 + 0x1230 + param_1);
  iVar1 = iVar3 * 0x4a0 + 0x1230 + param_1;
  if (cVar2 == -1) {
    if (*(char *)(param_1 + 0x24d6) == '\x01') {
      return 0xffffffff;
    }
    *(uint *)(param_1 + 0x24c0) = (uint)*(ushort *)(param_1 + 0x1200) * *(int *)(iVar1 + 0x2c);
    *(uint *)(param_1 + 0x24d8) = (uint)*(ushort *)(param_1 + 0x1200) * *(int *)(iVar1 + 0x2c);
    *(undefined1 *)(param_1 + 0x24d6) = 1;
    if (param_2[7] == 0) {
      *(int *)(param_1 + 0x24e4) = param_2[4] - param_2[8];
    }
    else {
      *(int *)(param_1 + 0x24e4) = (param_2[3] - param_2[7]) + *param_2;
    }
  }
  else {
    if ((int)cVar2 < *(int *)(param_1 + 0x24bc)) {
      if (((*(int *)(param_1 + 0x24b4) + -1 == iVar3) && (*(int *)(param_1 + 0x120c) == 3)) &&
         (*(char *)(param_1 + 0x24d6) == '\x01')) {
        return 0xffffffff;
      }
      *(undefined4 *)(param_1 + 0x24bc) = 0;
      *(int *)(param_1 + 0x24b8) = iVar3 + 1;
      if (*(int *)(param_1 + 0x24b4) == iVar3 + 1) {
        *(undefined1 *)(param_1 + 0x24d7) = 1;
        if (*(int *)(param_1 + 0x120c) != 3) {
          *(undefined1 *)(param_1 + 0x24d5) = 1;
          if (param_2[7] == 0) {
            *(int *)(param_1 + 0x24dc) = param_2[4] - param_2[8];
          }
          else {
            *(int *)(param_1 + 0x24dc) = (param_2[3] - param_2[7]) + *param_2;
          }
          *(undefined4 *)(param_1 + 0x24e0) = param_3;
          FUN_00550eb0(param_1,param_2,
                       ((*(uint *)(param_1 + 0x11fc) >> 3) / (uint)*(ushort *)(param_1 + 0x1200)) *
                       (uint)*(ushort *)(param_1 + 0x1200));
          return 0;
        }
        *(undefined4 *)(param_1 + 0x24b8) = 0;
        *(undefined4 *)(param_1 + 0x24d8) = 0;
        *(undefined1 *)(param_1 + 0x24d6) = 1;
        if (param_2[7] == 0) {
          *(int *)(param_1 + 0x24e4) = param_2[4] - param_2[8];
        }
        else {
          *(int *)(param_1 + 0x24e4) = (param_2[3] - param_2[7]) + *param_2;
        }
      }
    }
    *(undefined4 *)(param_1 + 0x24c0) = 0;
  }
  FUN_00596ef0(*(int *)(param_1 + 0x24b8) * 0x4a0 + 0x1264 + param_1,
               *(int *)(param_1 + 0x24c0) / (int)(uint)*(ushort *)(param_1 + 0x1200));
  return 0;
}

