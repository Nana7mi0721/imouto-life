
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

LRESULT FUN_00564b10(HWND param_1,uint param_2,uint param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  LRESULT LVar6;
  uint uVar7;
  int *piVar8;
  int iVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined4 unaff_retaddr;
  int local_8;
  
  if (((((int)DAT_00aa84b0 < 0) || ((DAT_00aa84b0 & 0x7c000000) != 0x24000000)) ||
      (uVar7 = DAT_00aa84b0 & 0xffff, 0xff < uVar7)) ||
     ((piVar8 = &DAT_00aa84b8 + uVar7 * 0x17, *piVar8 == 0 ||
      ((&DAT_00aa84bc)[uVar7 * 0x17] * 0x10000 != (DAT_00aa84b0 & 0x3ff0000))))) {
    piVar8 = (int *)0x0;
  }
  iVar9 = 0;
  _DAT_00aa8430 = 1;
  _DAT_00aa84a4 = FUN_00550060(0);
  DAT_00aa84ac = 1;
  if (param_2 < 0x282) {
    if (param_2 == 0x281) {
      LVar6 = DefWindowProcW(param_1,0x281,param_3,0);
      return LVar6;
    }
    if (param_2 == 0x10d) {
      DAT_00aa5ff4 = 0;
      _DAT_00aa5ff0 = 1;
      return 0;
    }
    if (param_2 == 0x10e) {
      FUN_0056d380(&DAT_00aa5ff8,0,0x400);
      _DAT_00aa5ff0 = 0;
      return 0;
    }
    if (param_2 == 0x10f) {
      uVar3 = (*DAT_00aba12c)(param_1);
      if ((param_3 & 8) != 0) {
        FUN_0056d380(&DAT_00aa5ff8,0,0x400);
        (*DAT_00aba14c)(uVar3,8,&DAT_00aa5ff8,0x400);
      }
      if ((param_3 & 0x800) != 0) {
        FUN_0056d380(&DAT_00aa5ff8,0,0x400);
        (*DAT_00aba14c)(uVar3,0x800,&DAT_00aa5ff8,0x400);
        iVar4 = FUN_0050e220(&DAT_00aa5ff8);
        if (0 < iVar4) {
          do {
            FUN_00563ac0((&DAT_00aa5ff8)[iVar9]);
            iVar9 = iVar9 + 1;
          } while (iVar9 < iVar4);
        }
        FUN_0056d380(&DAT_00aa5ff8,0,0x802);
        (*DAT_00aba14c)(uVar3,8,&DAT_00aa5ff8,0x400);
        if (DAT_00aa6ffc != 0) {
          FUN_0056e1d0(DAT_00aa6ffc);
          DAT_00aa6ffc = 0;
          DAT_00aa7000 = 0;
        }
      }
      iVar9 = DAT_00aa5ff4;
      if ((char)param_3 < '\0') {
        uVar5 = (*DAT_00aba14c)(uVar3,0x80,0,0);
        DAT_00aa5ff4 = FUN_00563c00(&DAT_00aa5ff8,uVar5);
        if ((DAT_00aa6ffc != 0) && (iVar9 != DAT_00aa5ff4)) {
          FUN_0056e1d0(DAT_00aa6ffc);
          DAT_00aa6ffc = 0;
          DAT_00aa7000 = 0;
        }
      }
      if ((param_3 & 0x20) != 0) {
        FUN_0056d380(&DAT_00aa7028,0,0x1000);
        iVar9 = (*DAT_00aba14c)(uVar3,0x20,&DAT_00aa7028,0x1000);
        DAT_00aa8028 = (int)(iVar9 + (iVar9 >> 0x1f & 3U)) >> 2;
      }
      if ((param_3 & 0x10) != 0) {
        FUN_0056d380(&DAT_00aa802c,0,0x400);
        DAT_00aa842c = (*DAT_00aba14c)(uVar3,0x10,&DAT_00aa802c,0x400);
      }
      (*DAT_00aba130)(unaff_retaddr,uVar3);
      return 0;
    }
  }
  else if (param_2 == 0x282) {
    switch(param_3) {
    case 3:
    case 5:
    case 9:
      if (DAT_00aae0bc == 0) {
        uVar3 = (*DAT_00aba12c)(param_1);
        iVar9 = (*DAT_00aba144)(uVar3,0,0,0);
        if (iVar9 != 0) {
          DAT_00aa7000 = iVar9;
          if (DAT_00aa6ffc != 0) {
            FUN_0056e1d0(DAT_00aa6ffc);
          }
          DAT_00aa6ffc = FUN_0056e030(iVar9,
                                      "..\\..\\..\\..\\Source\\Library\\Main\\DxInputString.cpp",
                                      0x4c6);
          if (DAT_00aa6ffc == 0) {
            (*DAT_00aba130)(param_1,uVar3);
            LVar6 = FUN_0052eaa0(&DAT_007d6b48,iVar9);
            return LVar6;
          }
          iVar4 = (*DAT_00aba144)(uVar3,0,DAT_00aa6ffc,iVar9);
          if (iVar4 == 0) {
            FUN_0056e1d0(DAT_00aa6ffc);
            DAT_00aa6ffc = 0;
            (*DAT_00aba130)(param_1,uVar3);
            FUN_0056bca0(&DAT_007d6bf4,iVar9);
            return 0;
          }
        }
        (*DAT_00aba130)(param_1,uVar3);
        return 0;
      }
      break;
    case 4:
      if (DAT_00aa6ffc != 0) {
        FUN_0056e1d0(DAT_00aa6ffc);
      }
      DAT_00aa6ffc = 0;
      DAT_00aa7000 = 0;
      break;
    default:
      LVar6 = DefWindowProcW(param_1,0x282,param_3,(LPARAM)param_4);
      return LVar6;
    case 8:
      if (DAT_00aae0cc == 0) {
        DAT_00aae0cc = 1;
        DefWindowProcW(param_1,0x282,param_3,(LPARAM)param_4);
        uVar10 = FUN_00550090(0);
        iVar9 = (int)((ulonglong)uVar10 >> 0x20);
        while (iVar4 = FUN_005501a0(), iVar4 == 0) {
          uVar11 = FUN_00550090(0);
          iVar4 = (int)((ulonglong)uVar11 >> 0x20);
          uVar7 = (uint)((uint)uVar11 < (uint)uVar10);
          uVar2 = iVar4 - iVar9;
          if ((-1 < (int)(uVar2 - uVar7)) &&
             ((uVar2 != uVar7 && SBORROW4(iVar4,iVar9) == SBORROW4(uVar2,uVar7) ||
              (1999 < (uint)uVar11 - (uint)uVar10)))) break;
        }
        DAT_00aae0cc = 0;
        uVar3 = (*DAT_00aba12c)(param_1);
        DAT_00aa7010 = (*DAT_00aba134)(uVar3);
        (*DAT_00aba130)(param_1,uVar3);
        return 0;
      }
    }
  }
  else if (param_2 == 0x288) {
    if ((piVar8 == (int *)0x0) || (param_3 != 4)) {
      DefWindowProcW(param_1,0x288,param_3,(LPARAM)param_4);
      return 0;
    }
    iVar9 = piVar8[6];
    param_2 = 0;
    if (iVar9 == -1) {
      local_8 = FUN_0050e220(piVar8[10]);
    }
    else {
      param_2 = piVar8[7];
      if ((int)param_2 < iVar9) {
        local_8 = iVar9 - param_2;
      }
      else {
        local_8 = param_2 - iVar9;
        param_2 = iVar9;
      }
    }
    if (param_4 == (undefined4 *)0x0) {
      return local_8 * 2 + 0x22;
    }
    puVar1 = param_4 + 8;
    if (iVar9 == -1) {
      FUN_0056cf10(puVar1,piVar8[10]);
    }
    else {
      FUN_0056d420(puVar1,piVar8[10] + param_2 * 2,local_8 * 2);
      *(undefined2 *)(local_8 * 2 + (int)puVar1) = 0;
    }
    param_4[2] = local_8;
    param_4[3] = 0x20;
    param_4[6] = 0;
    param_4[7] = 0;
    iVar9 = (*DAT_00aba12c)(param_1);
    if (iVar9 != 0) {
      if (piVar8[6] == -1) {
        param_4[5] = piVar8[9] * 2;
        uVar3 = FUN_0050e220(piVar8[10]);
        param_4[4] = uVar3;
      }
      else {
        param_4[5] = 0;
        param_4[4] = local_8;
      }
      uVar3 = 0x20000;
      (*DAT_00aba150)(iVar9,0x20000,param_4,*param_4,0,0);
      iVar4 = (*DAT_00aba150)(iVar9,0x10000,param_4,*param_4,0,0);
      if (iVar4 != 0) {
        if (piVar8[6] == -1) {
          uVar7 = (uint)param_4[5] >> 1;
          piVar8[6] = uVar7;
          piVar8[7] = param_4[4] + uVar7;
          piVar8[9] = uVar7;
        }
        FUN_00563b90();
      }
      (*DAT_00aba130)(uVar3,iVar9);
      return 0;
    }
  }
  return 0;
}

