
int FUN_007979c0(int *param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  if ((((param_3 < 0x100) && (0 < param_3)) && (param_5 <= param_4)) &&
     (((0 < param_4 && (-1 < param_5)) && (param_4 <= 0xff - param_5)))) {
    param_1[2] = param_5;
    iVar1 = 0;
    *param_1 = param_3;
    param_1[1] = param_4;
    if (0 < param_3) {
      do {
        *(undefined1 *)((int)param_1 + iVar1 + 0xc) = *(undefined1 *)(iVar1 + param_6);
        iVar1 = iVar1 + 1;
      } while (iVar1 < *param_1);
    }
    iVar1 = FUN_00799b00(param_1);
    if (iVar1 != 0) {
      piVar5 = param_1 + 0x43;
      iVar1 = FUN_00798960(2);
      iVar2 = FUN_00798960(1);
      iVar4 = 0;
      if (0 < param_1[2]) {
        do {
          iVar3 = FUN_007989b0(piVar5,param_2,2);
          if (iVar3 != 0) {
            return iVar3;
          }
          iVar4 = iVar4 + 1;
          piVar5 = (int *)((int)piVar5 + (iVar1 + 3U & 0xfffffffc));
        } while (iVar4 < param_1[2]);
      }
      if (iVar4 < param_1[1]) {
        do {
          iVar1 = FUN_007989b0(piVar5,param_2,1);
          if (iVar1 != 0) {
            return iVar1;
          }
          iVar4 = iVar4 + 1;
          piVar5 = (int *)((int)piVar5 + (iVar2 + 3U & 0xfffffffc));
        } while (iVar4 < param_1[1]);
      }
      return 0;
    }
  }
  return -1;
}

