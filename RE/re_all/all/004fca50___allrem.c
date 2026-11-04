
/* Library Function - Single Match
    __allrem
   
   Library: Visual Studio */

undefined8 __allrem(uint param_1,uint param_2,uint param_3,uint param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  bool bVar11;
  bool bVar12;
  
  bVar12 = (int)param_2 < 0;
  if (bVar12) {
    bVar11 = param_1 != 0;
    param_1 = -param_1;
    param_2 = -(uint)bVar11 - param_2;
  }
  uVar10 = (uint)bVar12;
  if ((int)param_4 < 0) {
    bVar12 = param_3 != 0;
    param_3 = -param_3;
    param_4 = -(uint)bVar12 - param_4;
  }
  if (param_4 == 0) {
    iVar6 = (int)(((ulonglong)param_2 % (ulonglong)param_3 << 0x20 | (ulonglong)param_1) %
                 (ulonglong)param_3);
    iVar7 = 0;
    if ((int)(uVar10 - 1) < 0) goto LAB_004fcafd;
  }
  else {
    uVar5 = param_1;
    uVar4 = param_3;
    uVar8 = param_2;
    uVar9 = param_4;
    do {
      uVar3 = uVar9 & 1;
      uVar9 = uVar9 >> 1;
      uVar4 = (uint)(CONCAT14(uVar3 != 0,uVar4) >> 1);
      uVar3 = uVar8 & 1;
      uVar8 = uVar8 >> 1;
      uVar5 = (uint)(CONCAT14(uVar3 != 0,uVar5) >> 1);
    } while (uVar9 != 0);
    uVar1 = CONCAT44(uVar8,uVar5) / (ulonglong)uVar4;
    uVar4 = (int)uVar1 * param_4;
    lVar2 = (uVar1 & 0xffffffff) * (ulonglong)param_3;
    uVar8 = (uint)((ulonglong)lVar2 >> 0x20);
    uVar5 = (uint)lVar2;
    uVar9 = uVar8 + uVar4;
    if (((CARRY4(uVar8,uVar4)) || (param_2 < uVar9)) || ((param_2 <= uVar9 && (param_1 < uVar5)))) {
      bVar12 = uVar5 < param_3;
      uVar5 = uVar5 - param_3;
      uVar9 = (uVar9 - param_4) - (uint)bVar12;
    }
    iVar6 = uVar5 - param_1;
    iVar7 = (uVar9 - param_2) - (uint)(uVar5 < param_1);
    if (-1 < (int)(uVar10 - 1)) goto LAB_004fcafd;
  }
  bVar12 = iVar6 != 0;
  iVar6 = -iVar6;
  iVar7 = -(uint)bVar12 - iVar7;
LAB_004fcafd:
  return CONCAT44(iVar7,iVar6);
}

