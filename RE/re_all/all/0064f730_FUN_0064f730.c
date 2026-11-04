
undefined4 FUN_0064f730(undefined4 *param_1,uint param_2,undefined4 *param_3)

{
  double dVar1;
  byte bVar2;
  short sVar3;
  undefined2 uVar4;
  int *piVar5;
  char *pcVar6;
  double *pdVar7;
  int iVar8;
  byte *pbVar9;
  uint uVar10;
  undefined4 *puVar11;
  char *pcVar12;
  bool bVar13;
  
  piVar5 = (int *)FUN_00653760(param_1,param_2,0);
  if ((short)piVar5[6] == 0x41) {
    uVar10 = 0;
  }
  else {
    if (0x12d < param_2) {
      if (param_2 < 0x213) {
        if (param_2 == 0x212) {
          *(undefined2 *)*param_3 = *(undefined2 *)(param_1 + 0x30);
          *(undefined2 *)param_3[1] = *(undefined2 *)((int)param_1 + 0xc2);
          return 1;
        }
        switch(param_2) {
        case 0x140:
          *(undefined4 *)*param_3 = param_1[0x23];
          *(undefined4 *)param_3[1] = param_1[0x24];
          *(undefined4 *)param_3[2] = param_1[0x25];
          return 1;
        case 0x141:
          *(undefined2 *)*param_3 = *(undefined2 *)(param_1 + 0x26);
          *(undefined2 *)param_3[1] = *(undefined2 *)((int)param_1 + 0x9a);
          return 1;
        case 0x142:
          *(undefined4 *)*param_3 = param_1[0x11];
          return 1;
        case 0x143:
          *(undefined4 *)*param_3 = param_1[0x12];
          return 1;
        case 0x144:
          goto switchD_0064f78b_caseD_111;
        case 0x145:
          goto switchD_0064f78b_caseD_117;
        default:
          goto switchD_0064f78b_caseD_ff;
        case 0x14a:
          *(undefined2 *)*param_3 = *(undefined2 *)(param_1 + 0x2e);
          *(undefined4 *)param_3[1] = param_1[0x2f];
          return 1;
        case 0x14d:
          *(undefined4 *)*param_3 = param_1[0x37];
          return 1;
        case 0x152:
          *(undefined2 *)*param_3 = *(undefined2 *)(param_1 + 0x27);
          *(undefined4 *)param_3[1] = param_1[0x28];
          return 1;
        case 0x153:
          *(undefined2 *)*param_3 = *(undefined2 *)((int)param_1 + 0x56);
          return 1;
        case 0x154:
          if ((param_1[3] & 0x400000) != 0) {
            *(undefined4 *)*param_3 = param_1[0x1b];
            return 1;
          }
          pdVar7 = (double *)param_1[0x1b];
          dVar1 = *pdVar7;
          if (1 < *(ushort *)((int)param_1 + 0x62)) {
            iVar8 = *(ushort *)((int)param_1 + 0x62) - 1;
            do {
              pdVar7 = pdVar7 + 1;
              if (*pdVar7 < dVar1) {
                dVar1 = *pdVar7;
              }
              iVar8 = iVar8 + -1;
            } while (iVar8 != 0);
          }
          *(double *)*param_3 = dVar1;
          return 1;
        case 0x155:
          if ((param_1[3] & 0x400000) != 0) {
            *(undefined4 *)*param_3 = param_1[0x1c];
            return 1;
          }
          pdVar7 = (double *)param_1[0x1c];
          dVar1 = *pdVar7;
          if (1 < *(ushort *)((int)param_1 + 0x62)) {
            iVar8 = *(ushort *)((int)param_1 + 0x62) - 1;
            do {
              pdVar7 = pdVar7 + 1;
              if (dVar1 < *pdVar7) {
                dVar1 = *pdVar7;
              }
              iVar8 = iVar8 + -1;
            } while (iVar8 != 0);
          }
          *(double *)*param_3 = dVar1;
          return 1;
        }
      }
      if (param_2 < 0x80e5) {
        if (param_2 == 0x80e4) {
          switch(*(undefined2 *)((int)param_1 + 0x56)) {
          case 1:
            *(undefined2 *)*param_3 = 2;
            return 1;
          case 2:
            *(undefined2 *)*param_3 = 1;
            return 1;
          case 3:
            *(undefined2 *)*param_3 = 3;
            return 1;
          case 4:
            *(undefined2 *)*param_3 = 0;
            return 1;
          default:
            return 1;
          }
        }
        if (param_2 == 0x213) {
          *(undefined2 *)*param_3 = *(undefined2 *)(param_1 + 0x31);
          return 1;
        }
        if (param_2 == 0x214) {
          *(undefined4 *)*param_3 = param_1[0x35];
          return 1;
        }
        if (param_2 == 0x80e3) {
          uVar4 = 1;
          if ((*(short *)(param_1 + 0x27) != 1) || (*(short *)param_1[0x28] != 1)) {
            uVar4 = 0;
          }
          *(undefined2 *)*param_3 = uVar4;
          return 1;
        }
      }
      else {
        if (param_2 == 0x80e5) {
          *(undefined4 *)*param_3 = param_1[0x10];
          return 1;
        }
        if (param_2 == 0x80e6) {
          *(undefined4 *)*param_3 = param_1[0x13];
          return 1;
        }
      }
      goto switchD_0064f78b_caseD_ff;
    }
    uVar10 = param_2;
    if (param_2 == 0x12d) {
      *(undefined4 *)*param_3 = param_1[0x32];
      if ((int)((uint)*(ushort *)((int)param_1 + 0x62) - (uint)*(ushort *)(param_1 + 0x27)) < 2) {
        return 1;
      }
      *(undefined4 *)param_3[1] = param_1[0x33];
      *(undefined4 *)param_3[2] = param_1[0x34];
      return 1;
    }
  }
  switch(uVar10) {
  case 0xfe:
    *(undefined4 *)*param_3 = param_1[0x14];
    return 1;
  case 0x100:
    *(undefined4 *)*param_3 = param_1[0xe];
    return 1;
  case 0x101:
    *(undefined4 *)*param_3 = param_1[0xf];
    return 1;
  case 0x102:
    *(undefined2 *)*param_3 = *(undefined2 *)(param_1 + 0x15);
    return 1;
  case 0x103:
    *(undefined2 *)*param_3 = *(undefined2 *)(param_1 + 0x16);
    return 1;
  case 0x106:
    *(undefined2 *)*param_3 = *(undefined2 *)((int)param_1 + 0x5a);
    return 1;
  case 0x107:
    *(undefined2 *)*param_3 = *(undefined2 *)(param_1 + 0x17);
    return 1;
  case 0x10a:
    *(undefined2 *)*param_3 = *(undefined2 *)((int)param_1 + 0x5e);
    return 1;
  case 0x111:
switchD_0064f78b_caseD_111:
    FUN_0065f680(param_1);
    *(undefined4 *)*param_3 = param_1[0x2b];
    return 1;
  case 0x112:
    *(undefined2 *)*param_3 = *(undefined2 *)(param_1 + 0x18);
    return 1;
  case 0x115:
    *(undefined2 *)*param_3 = *(undefined2 *)((int)param_1 + 0x62);
    return 1;
  case 0x116:
    *(undefined4 *)*param_3 = param_1[0x19];
    return 1;
  case 0x117:
switchD_0064f78b_caseD_117:
    FUN_0065f680(param_1);
    *(undefined4 *)*param_3 = param_1[0x2c];
    return 1;
  case 0x118:
    *(undefined2 *)*param_3 = *(undefined2 *)(param_1 + 0x1a);
    return 1;
  case 0x119:
    *(undefined2 *)*param_3 = *(undefined2 *)((int)param_1 + 0x6a);
    return 1;
  case 0x11a:
    *(undefined4 *)*param_3 = param_1[0x1d];
    return 1;
  case 0x11b:
    *(undefined4 *)*param_3 = param_1[0x1e];
    return 1;
  case 0x11c:
    *(undefined2 *)*param_3 = *(undefined2 *)((int)param_1 + 0x7e);
    return 1;
  case 0x11e:
    *(undefined4 *)*param_3 = param_1[0x20];
    return 1;
  case 0x11f:
    *(undefined4 *)*param_3 = param_1[0x21];
    return 1;
  case 0x128:
    *(undefined2 *)*param_3 = *(undefined2 *)(param_1 + 0x1f);
    return 1;
  case 0x129:
    *(undefined2 *)*param_3 = *(undefined2 *)(param_1 + 0x22);
    *(undefined2 *)param_3[1] = *(undefined2 *)((int)param_1 + 0x8a);
    return 1;
  }
switchD_0064f78b_caseD_ff:
  if (piVar5 == (int *)0x0) {
    pcVar12 = s_Unknown_00a068cc;
  }
  else {
    if ((short)piVar5[6] == 0x41) {
      iVar8 = 0;
      if ((int)param_1[0x38] < 1) {
        return 0;
      }
      puVar11 = (undefined4 *)param_1[0x39];
      while (*(uint *)*puVar11 != param_2) {
        iVar8 = iVar8 + 1;
        puVar11 = puVar11 + 3;
        if ((int)param_1[0x38] <= iVar8) {
          return 0;
        }
      }
      if (*(char *)((int)piVar5 + 0x1b) != '\0') {
        if ((short)piVar5[1] == -3) {
          *(undefined4 *)*param_3 = puVar11[1];
          *(undefined4 *)param_3[1] = puVar11[2];
          return 1;
        }
        *(undefined2 *)*param_3 = *(undefined2 *)(puVar11 + 1);
        *(undefined4 *)param_3[1] = puVar11[2];
        return 1;
      }
      if (*piVar5 == 0x150) {
        pbVar9 = (byte *)piVar5[7];
        pcVar12 = s_DotRange_00a067ec;
        do {
          bVar2 = *pbVar9;
          bVar13 = bVar2 < (byte)*pcVar12;
          if (bVar2 != *pcVar12) {
LAB_0064fdc1:
            iVar8 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
            goto LAB_0064fdc6;
          }
          if (bVar2 == 0) break;
          bVar2 = pbVar9[1];
          bVar13 = bVar2 < (byte)pcVar12[1];
          if (bVar2 != pcVar12[1]) goto LAB_0064fdc1;
          pbVar9 = pbVar9 + 2;
          pcVar12 = pcVar12 + 2;
        } while (bVar2 != 0);
        iVar8 = 0;
LAB_0064fdc6:
        if (iVar8 == 0) {
          *(undefined2 *)*param_3 = *(undefined2 *)puVar11[2];
          *(undefined2 *)param_3[1] = *(undefined2 *)(puVar11[2] + 2);
          return 1;
        }
      }
      if ((((piVar5[2] == 2) || (sVar3 = (short)piVar5[1], sVar3 == -1)) || (sVar3 == -3)) ||
         ((sVar3 == -2 || (1 < (int)puVar11[1])))) {
        *(undefined4 *)*param_3 = puVar11[2];
        return 1;
      }
      puVar11 = (undefined4 *)puVar11[2];
      switch(piVar5[2]) {
      case 1:
      case 6:
      case 7:
        *(undefined1 *)*param_3 = *(undefined1 *)puVar11;
        return 1;
      default:
        return 0;
      case 3:
      case 8:
        *(undefined2 *)*param_3 = *(undefined2 *)puVar11;
        return 1;
      case 4:
      case 5:
      case 9:
      case 10:
      case 0xb:
      case 0xd:
        *(undefined4 *)*param_3 = *puVar11;
        return 1;
      case 0xc:
      case 0x10:
      case 0x11:
      case 0x12:
        param_3 = (undefined4 *)*param_3;
        *param_3 = *puVar11;
        param_3[1] = puVar11[1];
        return 1;
      }
    }
    pcVar12 = (char *)piVar5[7];
  }
  pcVar6 = s_pseudo__00a067b4;
  if (param_2 < 0x10000) {
    pcVar6 = &DAT_00f3fa48;
  }
  FUN_006512e0(param_1[0x9d],s__TIFFVGetField_00a06984,s__s__Invalid__stag___s___not_supp_00a067bc,
               *param_1,pcVar6,pcVar12);
  return 0;
}

