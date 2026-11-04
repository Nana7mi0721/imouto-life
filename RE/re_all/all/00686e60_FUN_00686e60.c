
int FUN_00686e60(int *param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  iVar2 = param_1[param_2 + 0x16];
  if (iVar2 == 0) {
    *(undefined4 *)(*param_1 + 0x14) = 0x36;
    *(int *)(*param_1 + 0x18) = param_2;
    (**(code **)*param_1)(param_1);
  }
  iVar5 = 0;
  if (-1 < param_1[0x5d]) {
    piVar4 = (int *)param_1[0x5c];
    iVar3 = param_1[0x5d] + 1;
    do {
      if (0xff < *(ushort *)(iVar2 + *piVar4 * 2)) {
        iVar5 = 1;
      }
      piVar4 = piVar4 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  if (*(char *)(iVar2 + 0x80) == '\0') {
    FUN_00686af0(param_1,0xdb);
    if (iVar5 == 0) {
      iVar3 = param_1[0x5d] + 4;
    }
    else {
      iVar3 = param_1[0x5d] * 2 + 5;
    }
    FUN_00686b50(param_1,iVar3);
    FUN_00686b10(param_1,iVar5 * 0x10 + param_2);
    iVar3 = 0;
    if (-1 < param_1[0x5d]) {
      do {
        uVar1 = *(ushort *)(iVar2 + *(int *)(param_1[0x5c] + iVar3 * 4) * 2);
        if (iVar5 != 0) {
          FUN_00686b10(param_1,uVar1 >> 8);
        }
        FUN_00686b10(param_1,uVar1 & 0xff);
        iVar3 = iVar3 + 1;
      } while (iVar3 <= param_1[0x5d]);
    }
    *(undefined1 *)(iVar2 + 0x80) = 1;
  }
  return iVar5;
}

