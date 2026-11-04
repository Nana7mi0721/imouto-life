
longlong FUN_005f8150(int param_1,uint param_2,int param_3,undefined4 *param_4)

{
  uint uVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int extraout_EDX;
  bool bVar6;
  longlong lVar7;
  
  iVar5 = param_3;
  uVar3 = param_2;
  lVar2 = -1;
  do {
    bVar6 = 0xffff < param_2;
    param_2 = param_2 - 0x10000;
    param_3 = param_3 + -1 + (uint)bVar6;
    if ((param_3 < 1) && (param_3 < 0)) {
      param_2 = 0;
      param_3 = 0;
    }
    iVar4 = FUN_006a9a90(param_1,param_2,param_3);
    if (iVar4 != 0) {
      return (longlong)iVar4;
    }
    if (*(int *)(param_1 + 0xc) <= iVar5) {
      if (*(int *)(param_1 + 0xc) < iVar5) goto LAB_005f81cf;
      uVar1 = *(uint *)(param_1 + 8);
      lVar7 = lVar2;
      while (lVar2 = lVar7, uVar1 < uVar3) {
LAB_005f81cf:
        do {
          *param_4 = 0;
          param_4[1] = 0;
          param_4[2] = 0;
          param_4[3] = 0;
          lVar7 = FUN_005f7ef0(param_1,param_4,uVar3 - *(uint *)(param_1 + 8),
                               (iVar5 - *(int *)(param_1 + 0xc)) -
                               (uint)(uVar3 < *(uint *)(param_1 + 8)));
          if (lVar7 == -0x80) {
            return -0x80;
          }
          if (lVar7 < 0) goto LAB_005f8224;
          lVar2 = lVar7;
        } while (*(int *)(param_1 + 0xc) < iVar5);
        if (iVar5 < *(int *)(param_1 + 0xc)) break;
        uVar1 = *(uint *)(param_1 + 8);
      }
    }
LAB_005f8224:
    if (lVar2 != -1) {
      lVar7 = lVar2;
      if (param_4[1] == 0) {
        iVar5 = FUN_006a9a90(param_1,lVar2);
        lVar7 = (longlong)iVar5;
        if (iVar5 == 0) {
          FUN_005f7ef0(param_1,param_4,0x10000,0);
          lVar7 = lVar2;
          if ((extraout_EDX < 1) && (extraout_EDX < 0)) {
            return -0x81;
          }
        }
      }
      return lVar7;
    }
  } while( true );
}

