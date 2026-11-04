
int FUN_0079f160(int param_1,uint param_2)

{
  longlong lVar1;
  byte bVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int extraout_EDX;
  int *piVar11;
  int extraout_EDX_00;
  int iVar12;
  int iVar13;
  int *piVar14;
  uint uVar15;
  int iVar16;
  int *piVar17;
  int local_1c;
  uint local_14;
  
  local_1c = 0x40000000;
  piVar11 = (int *)((param_2 & 1) * 0x40 + param_1);
  uVar4 = param_2;
  do {
    uVar5 = uVar4;
    piVar3 = piVar11;
    uVar4 = uVar5 - 1;
    if ((int)uVar4 < 1) {
      iVar6 = *piVar3;
      if ((iVar6 < 0xffef9f) && (-0xffef9f < iVar6)) {
        iVar6 = iVar6 * -0x80;
        __allmul(iVar6,iVar6 >> 0x1f,iVar6,iVar6 >> 0x1f);
        return (int)((ulonglong)((longlong)(0x40000000 - extraout_EDX_00) * (longlong)local_1c) >>
                    0x20) << 2;
      }
      return 0;
    }
    iVar6 = piVar3[uVar4];
    if (0xffef9e < iVar6) {
      return 0;
    }
    if (iVar6 < -0xffef9e) {
      return 0;
    }
    iVar6 = iVar6 * -0x80;
    iVar10 = iVar6 >> 0x1f;
    __allmul(iVar6,iVar10,iVar6,iVar10);
    iVar13 = 0x40000000 - extraout_EDX;
    iVar7 = iVar13;
    if (iVar13 < 1) {
      iVar7 = -iVar13;
    }
    if (iVar7 == 0) {
      iVar7 = 0x20;
    }
    else {
      iVar7 = FUN_007a22e0(iVar7);
      iVar7 = 0x20 - iVar7;
    }
    iVar8 = iVar13;
    if (iVar13 < 1) {
      iVar8 = -iVar13;
    }
    if (iVar8 == 0) {
      iVar8 = 0x20;
    }
    else {
      iVar8 = FUN_007a22e0(iVar8);
      iVar8 = 0x20 - iVar8;
    }
    uVar15 = iVar13 << ((byte)(iVar8 + -1) & 0x1f);
    iVar12 = (int)uVar15 >> 0x10;
    lVar1 = 0x1fffffff / (longlong)iVar12;
    iVar9 = (int)lVar1;
    iVar16 = (int)(short)lVar1;
    uVar15 = (((int)((uVar15 & 0xffff) * iVar16) >> 0x10) + iVar16 * iVar12) * -8;
    iVar9 = ((iVar9 >> 0xf) + 1 >> 1) * uVar15 + ((int)((uVar15 & 0xffff) * iVar16) >> 0x10) +
            ((int)uVar15 >> 0x10) * iVar16 + iVar9 * 0x10000;
    iVar8 = (0x1f - (iVar8 + -1)) - (0x20 - iVar7);
    bVar2 = (byte)iVar8;
    if (iVar8 < 1) {
      iVar8 = -0x80000000 >> (-bVar2 & 0x1f);
      iVar12 = 0x7fffffff >> (-bVar2 & 0x1f);
      if (iVar12 < iVar8) {
        if (iVar8 < iVar9) {
LAB_0079f2cd:
          iVar9 = iVar8;
        }
        else if (iVar9 < iVar12) {
          param_2 = iVar12 << (-bVar2 & 0x1f);
          goto LAB_0079f2f2;
        }
LAB_0079f2cf:
        param_2 = iVar9 << (-bVar2 & 0x1f);
      }
      else {
        if (iVar9 <= iVar12) {
          if (iVar8 <= iVar9) goto LAB_0079f2cf;
          goto LAB_0079f2cd;
        }
        param_2 = iVar12 << (-bVar2 & 0x1f);
      }
    }
    else if (iVar8 < 0x20) {
      param_2 = iVar9 >> (bVar2 & 0x1f);
    }
    else {
      param_2 = 0;
    }
LAB_0079f2f2:
    local_1c = (int)((ulonglong)((longlong)iVar13 * (longlong)local_1c) >> 0x20) << 2;
    piVar11 = (int *)((uVar4 & 1) * 0x40 + param_1);
    if (0 < (int)uVar4) {
      piVar14 = piVar3 + (uVar5 - 2);
      piVar17 = piVar11;
      local_14 = uVar4;
      do {
        __allmul(*piVar14,*piVar14 >> 0x1f,iVar6,iVar10);
        __allshr();
        iVar8 = __allshr();
        iVar13 = *(int *)(((int)piVar3 - (int)piVar11) + (int)piVar17);
        if (0x20 - iVar7 == 1) {
          iVar9 = __allshr();
          iVar9 = iVar9 + ((iVar13 - iVar8) * param_2 & 1);
        }
        else {
          __allshr();
          iVar9 = __allshr();
        }
        *piVar17 = iVar9;
        piVar14 = piVar14 + -1;
        piVar17 = piVar17 + 1;
        local_14 = local_14 - 1;
      } while (local_14 != 0);
    }
  } while( true );
}

