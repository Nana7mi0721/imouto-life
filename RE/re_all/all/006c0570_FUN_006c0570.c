
int FUN_006c0570(int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                undefined4 *param_5,undefined4 param_6,int *param_7)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int extraout_EDX;
  int extraout_EDX_00;
  undefined4 local_20;
  undefined4 local_1c;
  
  if (param_4 != (undefined4 *)0x0) {
    *param_5 = 0;
  }
  iVar1 = FUN_006a8260(param_7);
  while( true ) {
    if (iVar1 == 0) {
      if (*(int *)(param_1 + 0x5c) != 3) {
        return -0x84;
      }
      iVar1 = FUN_006a8360(param_7);
      if (*(int *)(param_1 + 0x1d8) == iVar1) {
        FUN_006a89a0(param_1 + 0x88,param_7);
      }
      iVar1 = param_1 + 0x88;
      iVar4 = FUN_006a8d90(iVar1,&local_20);
      if (iVar4 != -1) {
        while (iVar4 == 0) {
          while( true ) {
            iVar4 = *(int *)(param_1 + 0x34);
            uVar3 = *(uint *)(param_1 + 0x30);
            if ((0x7ffffffe < iVar4) && (0xfffefffe < uVar3)) {
              uVar3 = 0xfffeffff;
              iVar4 = 0x7fffffff;
            }
            FUN_006c03f0(param_1,param_7,uVar3 + 0x10000,iVar4 + (uint)(0xfffeffff < uVar3));
            if (extraout_EDX_00 < 0) {
              return -0x85;
            }
            iVar4 = FUN_006a8360(param_7);
            if (*(int *)(param_1 + 0x1d8) == iVar4) break;
            iVar4 = FUN_006a8260();
            if (iVar4 != 0) {
              return -0x85;
            }
          }
          FUN_006a89a0(iVar1,param_7);
          iVar4 = FUN_006a8d90(iVar1,&local_20);
          if (iVar4 == -1) {
            return -0x85;
          }
        }
        iVar4 = FUN_006c49c0(param_3,local_20,local_1c);
        if (iVar4 < 0) {
          return iVar4;
        }
        iVar1 = FUN_006a8d90(iVar1,&local_20);
        if ((iVar1 == 0) && (*(char *)(param_7[1] + -1 + *param_7) != -1)) {
          return 0;
        }
        FUN_006c4970(param_3);
      }
      return -0x85;
    }
    if (param_4 != (undefined4 *)0x0) {
      iVar1 = FUN_006c0870(param_7,*param_4,*param_5);
      if (iVar1 != 0) {
        return -0x85;
      }
      iVar1 = FUN_006c07f0(param_7,param_4,param_5,param_6);
      if (iVar1 < 0) {
        return iVar1;
      }
    }
    if (*(int *)(param_1 + 0x5c) < 3) {
      iVar1 = param_1 + 0x88;
      uVar2 = FUN_006a8360(param_7);
      FUN_006a8d60(iVar1,uVar2);
      FUN_006a89a0(iVar1,param_7);
      iVar1 = FUN_006a8d90(iVar1,&local_20);
      if (0 < iVar1) {
        iVar1 = FUN_006c46e0(param_2,local_20,local_1c);
        if (iVar1 < 0) {
          if (iVar1 != -0x84) {
            return iVar1;
          }
        }
        else {
          *(undefined4 *)(param_1 + 0x5c) = 3;
        }
      }
    }
    iVar1 = *(int *)(param_1 + 0x34);
    uVar3 = *(uint *)(param_1 + 0x30);
    if ((0x7ffffffe < iVar1) && (0xfffefffe < uVar3)) {
      uVar3 = 0xfffeffff;
      iVar1 = 0x7fffffff;
    }
    FUN_006c03f0(param_1,param_7,uVar3 + 0x10000,iVar1 + (uint)(0xfffeffff < uVar3));
    if (extraout_EDX < 0) break;
    iVar1 = FUN_006a8260(param_7);
  }
  return (*(int *)(param_1 + 0x5c) < 3) - 0x85;
}

