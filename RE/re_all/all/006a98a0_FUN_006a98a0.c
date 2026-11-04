
longlong FUN_006a98a0(int param_1,uint param_2,int param_3,undefined4 param_4,undefined4 param_5,
                     int *param_6,undefined8 *param_7)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  bool bVar8;
  longlong lVar9;
  undefined8 uVar10;
  undefined1 local_10 [16];
  
  iVar4 = param_3;
  uVar3 = param_2;
  lVar1 = -1;
  lVar2 = -1;
  iVar7 = -1;
  uVar10 = 0xffffffffffffffff;
  do {
    bVar8 = 0xffff < param_2;
    param_2 = param_2 - 0x10000;
    param_3 = param_3 + -1 + (uint)bVar8;
    if ((param_3 < 1) && (param_3 < 0)) {
      param_2 = 0;
      param_3 = 0;
    }
    iVar5 = FUN_006a9a90(param_1,param_2,param_3);
    if (iVar5 != 0) {
      return (longlong)iVar5;
    }
    iVar5 = *(int *)(param_1 + 0xc);
    uVar6 = *(uint *)(param_1 + 8);
    if ((iVar5 <= iVar4) && ((iVar5 < iVar4 || (uVar6 < uVar3)))) {
      while( true ) {
        lVar9 = FUN_006a94d0(param_1,local_10,uVar3 - uVar6,(iVar4 - iVar5) - (uint)(uVar3 < uVar6))
        ;
        if (lVar9 == -0x80) {
          return -0x80;
        }
        if (lVar9 < 0) break;
        iVar7 = FUN_006a8360(local_10);
        uVar10 = FUN_006a8280(local_10);
        if ((iVar7 == *param_6) && (iVar7 >> 0x1f == *param_6 >> 0x1f)) {
          *param_7 = uVar10;
          lVar1 = lVar9;
        }
        iVar5 = FUN_006a9690(iVar7,param_4,param_5);
        if (iVar5 == 0) {
          lVar1 = -1;
        }
        uVar6 = *(uint *)(param_1 + 8);
        iVar5 = *(int *)(param_1 + 0xc);
        lVar2 = lVar9;
        if ((iVar4 <= iVar5) && ((iVar4 < iVar5 || (uVar3 <= uVar6)))) break;
      }
    }
    if (lVar2 != -1) {
      if (lVar1 < 0) {
        *param_6 = iVar7;
        *param_7 = uVar10;
        return lVar2;
      }
      return lVar1;
    }
  } while( true );
}

