
undefined4 __fastcall FUN_00450460(int param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  int *piVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  int iVar11;
  wchar_t *pwVar12;
  int local_f0;
  int local_ec;
  undefined4 local_b4;
  undefined4 local_b0;
  int *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007ad99f;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -1;
  do {
    if (499999 < DAT_00a1434c) {
      ExceptionList = local_10;
      return 1;
    }
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
    DAT_00a0f814 = *(undefined4 *)(param_1 + 8);
    uVar7 = FUN_004cecd0();
    *(undefined4 *)(param_1 + 0x898) = uVar7;
    piVar8 = (int *)FUN_004ce990();
    iVar11 = *piVar8;
    if (iVar11 < 0xf2) {
      if (iVar11 == 0xf1) {
        uVar7 = FUN_004603c0();
        ExceptionList = local_10;
        return uVar7;
      }
      switch(iVar11) {
      default:
        goto switchD_00450535_caseD_0;
      case 0x65:
        uVar7 = FUN_00452710();
        ExceptionList = local_10;
        return uVar7;
      case 0x66:
        uVar7 = FUN_00452970();
        ExceptionList = local_10;
        return uVar7;
      case 0x67:
        break;
      case 0x68:
        uVar7 = FUN_00452a10();
        ExceptionList = local_10;
        return uVar7;
      case 0x69:
        uVar7 = FUN_00452a30();
        ExceptionList = local_10;
        return uVar7;
      case 0x6a:
        FUN_00452a50();
        break;
      case 0x6b:
        FUN_00452db0();
        break;
      case 0x6f:
        FUN_00452de0();
        break;
      case 0x70:
        FUN_00453370();
        break;
      case 0x79:
        FUN_00453720();
        break;
      case 0x7a:
        uVar7 = FUN_00455fc0();
        ExceptionList = local_10;
        return uVar7;
      case 0x7b:
        uVar7 = FUN_00458470();
        ExceptionList = local_10;
        return uVar7;
      case 0x7c:
        FUN_00458580();
        break;
      case 0x7d:
        FUN_0045a100();
        break;
      case 0x7e:
        FUN_0045a420();
        break;
      case 0x82:
        uVar7 = FUN_0045a780();
        ExceptionList = local_10;
        return uVar7;
      case 0x8c:
        FUN_0045abb0();
        break;
      case 0x8d:
        FUN_0045aff0();
        break;
      case 0x96:
        FUN_0045b100();
        break;
      case 0x97:
        uVar7 = FUN_0045ca90();
        ExceptionList = local_10;
        return uVar7;
      case 0xa0:
        uVar7 = FUN_0045cdd0();
        ExceptionList = local_10;
        return uVar7;
      case 0xa1:
        uVar7 = FUN_0045ce60();
        ExceptionList = local_10;
        return uVar7;
      case 0xa2:
        uVar7 = FUN_0045ceb0();
        ExceptionList = local_10;
        return uVar7;
      case 0xaa:
        FUN_0045cf00();
        break;
      case 0xab:
        FUN_0045d1a0();
        break;
      case 0xac:
        uVar7 = FUN_0045d2d0();
        ExceptionList = local_10;
        return uVar7;
      case 0xad:
        uVar7 = FUN_0045d2f0();
        ExceptionList = local_10;
        return uVar7;
      case 0xae:
        uVar7 = FUN_0045d4d0();
        ExceptionList = local_10;
        return uVar7;
      case 0xaf:
        uVar7 = FUN_0045d500();
        ExceptionList = local_10;
        return uVar7;
      case 0xb0:
        FUN_0045d1c0();
        break;
      case 0xb1:
        uVar7 = FUN_0045d520();
        ExceptionList = local_10;
        return uVar7;
      case 0xb2:
        uVar7 = FUN_0045d560();
        ExceptionList = local_10;
        return uVar7;
      case 0xb3:
        FUN_0045cf50();
        break;
      case 0xb4:
        uVar7 = FUN_0045d580();
        ExceptionList = local_10;
        return uVar7;
      case 0xc9:
        uVar7 = FUN_0045d5e0();
        ExceptionList = local_10;
        return uVar7;
      case 0xca:
        uVar7 = FUN_0045d690();
        ExceptionList = local_10;
        return uVar7;
      case 0xd2:
        uVar7 = FUN_0045d6b0();
        ExceptionList = local_10;
        return uVar7;
      case 0xd3:
        uVar7 = FUN_0045e350();
        ExceptionList = local_10;
        return uVar7;
      case 0xd5:
        FUN_0045f180();
        break;
      case 0xdc:
        uVar7 = FUN_0045fad0();
        ExceptionList = local_10;
        return uVar7;
      case 0xdd:
        uVar7 = FUN_0045fda0();
        ExceptionList = local_10;
        return uVar7;
      case 0xde:
        uVar7 = FUN_00460030();
        ExceptionList = local_10;
        return uVar7;
      case 0xe6:
        uVar7 = FUN_004602c0();
        ExceptionList = local_10;
        return uVar7;
      case 0xe7:
        uVar7 = FUN_004602e0();
        ExceptionList = local_10;
        return uVar7;
      case 0xf0:
        uVar7 = FUN_00460300();
        ExceptionList = local_10;
        return uVar7;
      case -1:
        FUN_00452450();
        ExceptionList = local_10;
        return 1;
      }
    }
    else if (iVar11 < 0x33451) {
      if (iVar11 == 210000) {
        puVar10 = (undefined4 *)FUN_004ce990();
        piVar8 = (int *)*puVar10;
        puVar10 = (undefined4 *)FUN_004ce990();
        iVar11 = *piVar8;
        iVar2 = *(int *)*puVar10;
        puVar10 = (undefined4 *)FUN_004ce990();
        *(int *)*puVar10 = iVar11 + iVar2;
      }
      else if (iVar11 < 0x1a5) {
        if (iVar11 == 0x1a4) {
          FUN_00467be0();
        }
        else {
          switch(iVar11) {
          case 0xf2:
            uVar7 = FUN_00460640();
            ExceptionList = local_10;
            return uVar7;
          default:
switchD_00450535_caseD_0:
            break;
          case 0xfa:
            FUN_00460bb0();
            break;
          case 0xfb:
            FUN_00465000();
            break;
          case 0x104:
            uVar7 = FUN_00465a00();
            ExceptionList = local_10;
            return uVar7;
          case 0x10e:
            uVar7 = FUN_00465d90();
            ExceptionList = local_10;
            return uVar7;
          case 0x118:
            uVar7 = FUN_00466b20();
            ExceptionList = local_10;
            return uVar7;
          case 0x119:
            uVar7 = FUN_00466c10();
            ExceptionList = local_10;
            return uVar7;
          case 0x122:
            uVar7 = FUN_00467070();
            ExceptionList = local_10;
            return uVar7;
          case 300:
            uVar7 = FUN_0045e4c0();
            ExceptionList = local_10;
            return uVar7;
          case 0x191:
            FUN_00467a90();
            break;
          case 0x192:
            FUN_00467b80();
          }
        }
      }
      else if (iVar11 < 0x1b19a) {
        if (iVar11 == 0x1b199) {
          *(undefined4 *)(param_1 + 0x38 + *(char *)(*(int *)(param_1 + 0x898) + 0x10) * 4) =
               0xffffff9c;
          puVar10 = (undefined4 *)FUN_004ce990();
          piVar8 = (int *)*puVar10;
          puVar10 = (undefined4 *)FUN_004ce990();
          if (*piVar8 < *(int *)*puVar10) {
            puVar10 = (undefined4 *)FUN_004ce990();
            *(undefined4 *)(param_1 + 8) = *puVar10;
          }
          else {
            puVar10 = (undefined4 *)FUN_004ce990();
            *(undefined4 *)(param_1 + 8) = *puVar10;
          }
        }
        else if (iVar11 < 500) {
          if (iVar11 == 499) {
            FUN_00467d30();
          }
          else if (iVar11 == 0x1a5) {
            FUN_00467cd0();
          }
          else {
            if (iVar11 != 0x1f2) goto switchD_00450535_caseD_0;
            FUN_0045d210();
          }
        }
        else {
          if (iVar11 == 0x2711) {
            uVar7 = FUN_00468cb0();
            ExceptionList = local_10;
            return uVar7;
          }
          if (iVar11 != 0x1b198) goto switchD_00450535_caseD_0;
          *(undefined4 *)(param_1 + 0x38 + *(char *)(*(int *)(param_1 + 0x898) + 0x10) * 4) =
               0xffffff9c;
          puVar10 = (undefined4 *)FUN_004ce990();
          piVar8 = (int *)*puVar10;
          puVar10 = (undefined4 *)FUN_004ce990();
          if (*(int *)*puVar10 < *piVar8) {
            puVar10 = (undefined4 *)FUN_004ce990();
            *(undefined4 *)(param_1 + 8) = *puVar10;
          }
          else {
            puVar10 = (undefined4 *)FUN_004ce990();
            *(undefined4 *)(param_1 + 8) = *puVar10;
          }
        }
      }
      else {
        switch(iVar11) {
        case 0x1b19a:
          *(undefined4 *)(param_1 + 0x38 + *(char *)(*(int *)(param_1 + 0x898) + 0x10) * 4) =
               0xffffff9c;
          puVar10 = (undefined4 *)FUN_004ce990();
          piVar8 = (int *)*puVar10;
          puVar10 = (undefined4 *)FUN_004ce990();
          if (*piVar8 == *(int *)*puVar10) {
            puVar10 = (undefined4 *)FUN_004ce990();
            *(undefined4 *)(param_1 + 8) = *puVar10;
          }
          else {
            puVar10 = (undefined4 *)FUN_004ce990();
            *(undefined4 *)(param_1 + 8) = *puVar10;
          }
          break;
        case 0x1b19b:
          *(undefined4 *)(param_1 + 0x38 + *(char *)(*(int *)(param_1 + 0x898) + 0x10) * 4) =
               0xffffff9c;
          puVar10 = (undefined4 *)FUN_004ce990();
          piVar8 = (int *)*puVar10;
          puVar10 = (undefined4 *)FUN_004ce990();
          if (*(int *)*puVar10 < *piVar8) {
            puVar10 = (undefined4 *)FUN_004ce990();
            *(undefined4 *)(param_1 + 8) = *puVar10;
          }
          else {
            puVar10 = (undefined4 *)FUN_004ce990();
            *(undefined4 *)(param_1 + 8) = *puVar10;
          }
          break;
        case 0x1b19c:
          *(undefined4 *)(param_1 + 0x38 + *(char *)(*(int *)(param_1 + 0x898) + 0x10) * 4) =
               0xffffff9c;
          puVar10 = (undefined4 *)FUN_004ce990();
          piVar8 = (int *)*puVar10;
          puVar10 = (undefined4 *)FUN_004ce990();
          if (*piVar8 < *(int *)*puVar10) {
            puVar10 = (undefined4 *)FUN_004ce990();
            *(undefined4 *)(param_1 + 8) = *puVar10;
          }
          else {
            puVar10 = (undefined4 *)FUN_004ce990();
            *(undefined4 *)(param_1 + 8) = *puVar10;
          }
          break;
        case 0x1b19d:
          *(undefined4 *)(param_1 + 0x38 + *(char *)(*(int *)(param_1 + 0x898) + 0x10) * 4) =
               0xffffff9c;
          puVar10 = (undefined4 *)FUN_004ce990();
          piVar8 = (int *)*puVar10;
          puVar10 = (undefined4 *)FUN_004ce990();
          if (*piVar8 == *(int *)*puVar10) {
            puVar10 = (undefined4 *)FUN_004ce990();
            *(undefined4 *)(param_1 + 8) = *puVar10;
          }
          else {
            puVar10 = (undefined4 *)FUN_004ce990();
            *(undefined4 *)(param_1 + 8) = *puVar10;
          }
          break;
        case 0x1b19e:
          *(undefined4 *)(param_1 + 0x38 + *(char *)(*(int *)(param_1 + 0x898) + 0x10) * 4) =
               0xffffff9c;
          puVar10 = (undefined4 *)FUN_004ce990();
          puVar4 = (uint *)*puVar10;
          puVar10 = (undefined4 *)FUN_004ce990();
          uVar5 = *puVar4;
          uVar6 = *(uint *)*puVar10;
          puVar10 = (undefined4 *)FUN_004ce990();
          if ((uVar5 & uVar6) == *(uint *)*puVar10) {
            puVar10 = (undefined4 *)FUN_004ce990();
            *(undefined4 *)(param_1 + 8) = *puVar10;
          }
          else {
            puVar10 = (undefined4 *)FUN_004ce990();
            *(undefined4 *)(param_1 + 8) = *puVar10;
          }
          break;
        default:
          goto switchD_00450535_caseD_0;
        }
      }
    }
    else if (iVar11 < 0x33479) {
      if (iVar11 == 0x33478) {
        puVar10 = (undefined4 *)FUN_004ce990();
        piVar8 = (int *)*puVar10;
        puVar9 = (undefined4 *)FUN_004ce990();
        piVar3 = (int *)*puVar9;
        puVar9 = (undefined4 *)FUN_004ce990();
        *(int *)*puVar10 = *piVar8 / (*piVar3 + *(int *)*puVar9);
      }
      else {
        switch(iVar11) {
        case 0x33451:
          puVar10 = (undefined4 *)FUN_004ce990();
          piVar8 = (int *)*puVar10;
          puVar10 = (undefined4 *)FUN_004ce990();
          iVar11 = *piVar8;
          iVar2 = *(int *)*puVar10;
          puVar10 = (undefined4 *)FUN_004ce990();
          *(int *)*puVar10 = iVar11 - iVar2;
          break;
        case 0x33452:
          puVar10 = (undefined4 *)FUN_004ce990();
          piVar8 = (int *)*puVar10;
          puVar10 = (undefined4 *)FUN_004ce990();
          iVar11 = *piVar8;
          iVar2 = *(int *)*puVar10;
          puVar10 = (undefined4 *)FUN_004ce990();
          *(int *)*puVar10 = iVar11 * iVar2;
          break;
        default:
          goto switchD_00450535_caseD_0;
        case 0x3345a:
          puVar10 = (undefined4 *)FUN_004ce990();
          piVar8 = (int *)*puVar10;
          puVar9 = (undefined4 *)FUN_004ce990();
          piVar3 = (int *)*puVar9;
          puVar9 = (undefined4 *)FUN_004ce990();
          *(int *)*puVar10 = *piVar3 + *(int *)*puVar9 + *piVar8;
          break;
        case 0x3345b:
          puVar10 = (undefined4 *)FUN_004ce990();
          piVar8 = (int *)*puVar10;
          puVar9 = (undefined4 *)FUN_004ce990();
          piVar3 = (int *)*puVar9;
          puVar9 = (undefined4 *)FUN_004ce990();
          *(int *)*puVar10 = (*piVar3 - *(int *)*puVar9) + *piVar8;
          break;
        case 0x3345c:
          puVar10 = (undefined4 *)FUN_004ce990();
          piVar8 = (int *)*puVar10;
          puVar9 = (undefined4 *)FUN_004ce990();
          piVar3 = (int *)*puVar9;
          puVar9 = (undefined4 *)FUN_004ce990();
          *(int *)*puVar10 = *piVar3 * *(int *)*puVar9 + *piVar8;
          break;
        case 0x33464:
          puVar10 = (undefined4 *)FUN_004ce990();
          piVar8 = (int *)*puVar10;
          puVar9 = (undefined4 *)FUN_004ce990();
          piVar3 = (int *)*puVar9;
          puVar9 = (undefined4 *)FUN_004ce990();
          *(int *)*puVar10 = *piVar8 - (*piVar3 + *(int *)*puVar9);
          break;
        case 0x33465:
          puVar10 = (undefined4 *)FUN_004ce990();
          piVar8 = (int *)*puVar10;
          puVar9 = (undefined4 *)FUN_004ce990();
          piVar3 = (int *)*puVar9;
          puVar9 = (undefined4 *)FUN_004ce990();
          *(int *)*puVar10 = *piVar8 - (*piVar3 - *(int *)*puVar9);
          break;
        case 0x33466:
          puVar10 = (undefined4 *)FUN_004ce990();
          piVar8 = (int *)*puVar10;
          puVar9 = (undefined4 *)FUN_004ce990();
          piVar3 = (int *)*puVar9;
          puVar9 = (undefined4 *)FUN_004ce990();
          *(int *)*puVar10 = *piVar8 - *piVar3 * *(int *)*puVar9;
          break;
        case 0x3346e:
          puVar10 = (undefined4 *)FUN_004ce990();
          piVar8 = (int *)*puVar10;
          puVar9 = (undefined4 *)FUN_004ce990();
          piVar3 = (int *)*puVar9;
          puVar9 = (undefined4 *)FUN_004ce990();
          *(int *)*puVar10 = (*piVar3 + *(int *)*puVar9) * *piVar8;
          break;
        case 0x3346f:
          puVar10 = (undefined4 *)FUN_004ce990();
          piVar8 = (int *)*puVar10;
          puVar9 = (undefined4 *)FUN_004ce990();
          piVar3 = (int *)*puVar9;
          puVar9 = (undefined4 *)FUN_004ce990();
          *(int *)*puVar10 = (*piVar3 - *(int *)*puVar9) * *piVar8;
          break;
        case 0x33470:
          puVar10 = (undefined4 *)FUN_004ce990();
          piVar8 = (int *)*puVar10;
          puVar9 = (undefined4 *)FUN_004ce990();
          piVar3 = (int *)*puVar9;
          puVar9 = (undefined4 *)FUN_004ce990();
          *(int *)*puVar10 = *piVar3 * *(int *)*puVar9 * *piVar8;
        }
      }
    }
    else if (iVar11 < 0x3d0f5) {
      if (iVar11 == 0x3d0f4) {
        puVar10 = (undefined4 *)FUN_004ce990();
        if (*(int *)*puVar10 < 0) {
          basic_string<>();
          local_8 = 0;
          FUN_00438b60();
          local_8 = CONCAT31(local_8._1_3_,1);
          basic_string<>(&DAT_007ced60);
          uVar7 = FUN_00401c50();
          basic_string<>(uVar7);
          local_8 = 0xffffffff;
          FUN_0042bed0();
        }
        else {
          FUN_004ce990();
          piVar8 = (int *)FUN_004ce990();
          if (*piVar8 == 0) {
            FUN_004ce990();
            iVar11 = FUN_004717c0();
            puVar10 = (undefined4 *)FUN_004ce990();
            if (iVar11 <= *(int *)*puVar10) {
              FUN_004ce990();
              FUN_004ce990();
              FUN_004779b0();
            }
          }
          puVar10 = (undefined4 *)FUN_004ce990();
          switch(*puVar10) {
          case 0:
            puVar10 = (undefined4 *)FUN_004ce990();
            puVar10 = (undefined4 *)*puVar10;
            FUN_004ce990();
            FUN_004ce990();
            FUN_004ce990();
            FUN_004d0120();
            FUN_004cfcd0();
            puVar9 = (undefined4 *)FUN_004ce990();
            *puVar9 = *puVar10;
            break;
          case 1:
            FUN_004ce990();
            FUN_004ce990();
            FUN_004ce990();
            FUN_004d0120();
            FUN_004cfcd0();
            piVar8 = (int *)FUN_004ce990();
            puVar10 = (undefined4 *)FUN_004ce990();
            *piVar8 = *piVar8 + *(int *)*puVar10;
            break;
          case 2:
            FUN_004ce990();
            FUN_004ce990();
            FUN_004ce990();
            FUN_004d0120();
            FUN_004cfcd0();
            piVar8 = (int *)FUN_004ce990();
            puVar10 = (undefined4 *)FUN_004ce990();
            *piVar8 = *piVar8 - *(int *)*puVar10;
            break;
          case 3:
            FUN_004ce990();
            FUN_004ce990();
            FUN_004ce990();
            FUN_004d0120();
            FUN_004cfcd0();
            piVar8 = (int *)FUN_004ce990();
            puVar10 = (undefined4 *)FUN_004ce990();
            *piVar8 = *piVar8 * *(int *)*puVar10;
            break;
          case 4:
            puVar10 = (undefined4 *)FUN_004ce990();
            if (*(int *)*puVar10 != 0) {
              FUN_004ce990();
              FUN_004ce990();
              FUN_004ce990();
              FUN_004d0120();
              FUN_004cfcd0();
              piVar8 = (int *)FUN_004ce990();
              puVar10 = (undefined4 *)FUN_004ce990();
              *piVar8 = *piVar8 / *(int *)*puVar10;
            }
            break;
          case 5:
            puVar10 = (undefined4 *)FUN_004ce990();
            if (*(int *)*puVar10 == 0) {
              FUN_004ce990();
              FUN_004ce990();
              FUN_004ce990();
              FUN_004d0120();
              FUN_004cfcd0();
              puVar10 = (undefined4 *)FUN_004ce990();
              *puVar10 = 1;
            }
            else {
              FUN_004ce990();
              FUN_004ce990();
              FUN_004ce990();
              FUN_004d0120();
              FUN_004cfcd0();
              piVar8 = (int *)FUN_004ce990();
              puVar10 = (undefined4 *)FUN_004ce990();
              *piVar8 = *piVar8 % *(int *)*puVar10;
            }
            break;
          case 6:
            FUN_004ce990();
            FUN_004ce990();
            FUN_004ce990();
            FUN_004d0120();
            FUN_004cfcd0();
            piVar8 = (int *)FUN_004ce990();
            puVar10 = (undefined4 *)FUN_004ce990();
            if (*piVar8 < *(int *)*puVar10) {
              puVar10 = (undefined4 *)FUN_004ce990();
              local_b0 = *(undefined4 *)*puVar10;
            }
            else {
              FUN_004ce990();
              FUN_004ce990();
              FUN_004ce990();
              FUN_004d0120();
              FUN_004cfcd0();
              puVar10 = (undefined4 *)FUN_004ce990();
              local_b0 = *puVar10;
            }
            FUN_004ce990();
            FUN_004ce990();
            FUN_004ce990();
            FUN_004d0120();
            FUN_004cfcd0();
            puVar10 = (undefined4 *)FUN_004ce990();
            *puVar10 = local_b0;
            break;
          case 7:
            FUN_004ce990();
            FUN_004ce990();
            FUN_004ce990();
            FUN_004d0120();
            FUN_004cfcd0();
            piVar8 = (int *)FUN_004ce990();
            puVar10 = (undefined4 *)FUN_004ce990();
            if (*(int *)*puVar10 < *piVar8) {
              puVar10 = (undefined4 *)FUN_004ce990();
              local_b4 = *(undefined4 *)*puVar10;
            }
            else {
              FUN_004ce990();
              FUN_004ce990();
              FUN_004ce990();
              FUN_004d0120();
              FUN_004cfcd0();
              puVar10 = (undefined4 *)FUN_004ce990();
              local_b4 = *puVar10;
            }
            FUN_004ce990();
            FUN_004ce990();
            FUN_004ce990();
            FUN_004d0120();
            FUN_004cfcd0();
            puVar10 = (undefined4 *)FUN_004ce990();
            *puVar10 = local_b4;
          }
        }
      }
      else if (iVar11 < 0x3d092) {
        if (iVar11 == 0x3d091) {
          puVar10 = (undefined4 *)FUN_004ce990();
          piVar8 = (int *)*puVar10;
          puVar9 = (undefined4 *)FUN_004ce990();
          *(int *)*puVar10 = *piVar8 + *(int *)*puVar9;
        }
        else if (iVar11 == 0x33479) {
          puVar10 = (undefined4 *)FUN_004ce990();
          piVar8 = (int *)*puVar10;
          puVar9 = (undefined4 *)FUN_004ce990();
          piVar3 = (int *)*puVar9;
          puVar9 = (undefined4 *)FUN_004ce990();
          *(int *)*puVar10 = *piVar8 / (*piVar3 - *(int *)*puVar9);
        }
        else {
          if (iVar11 != 250000) goto switchD_00450535_caseD_0;
          puVar10 = (undefined4 *)FUN_004ce990();
          puVar10 = (undefined4 *)*puVar10;
          puVar9 = (undefined4 *)FUN_004ce990();
          *(undefined4 *)*puVar9 = *puVar10;
        }
      }
      else if (iVar11 == 0x3d092) {
        puVar10 = (undefined4 *)FUN_004ce990();
        piVar8 = (int *)*puVar10;
        puVar9 = (undefined4 *)FUN_004ce990();
        *(int *)*puVar10 = *piVar8 - *(int *)*puVar9;
      }
      else {
        if (iVar11 != 0x3d093) goto switchD_00450535_caseD_0;
        puVar10 = (undefined4 *)FUN_004ce990();
        piVar8 = (int *)*puVar10;
        puVar9 = (undefined4 *)FUN_004ce990();
        *(int *)*puVar10 = *piVar8 * *(int *)*puVar9;
      }
    }
    else if (iVar11 < 0x79951) {
      if (iVar11 == 0x79950) {
        puVar10 = (undefined4 *)FUN_004ce990();
        *(undefined4 *)(param_1 + 8) = *puVar10;
      }
      else if (iVar11 == 0x3d0f5) {
        puVar10 = (undefined4 *)FUN_004ce990();
        if (*(int *)*puVar10 < 0) {
          basic_string<>();
          local_8 = 2;
          FUN_00438b60();
          local_8 = CONCAT31(local_8._1_3_,3);
          basic_string<>(&DAT_007ced84);
          uVar7 = FUN_00401c50();
          basic_string<>(uVar7);
          local_8 = 0xffffffff;
          FUN_0042bed0();
        }
        else {
          piVar8 = (int *)FUN_004ce990();
          if (*piVar8 == 1) {
LAB_00451cfa:
            FUN_004ce990();
            FUN_004ce990();
            FUN_004ce990();
            FUN_004ce990();
            FUN_004d0120();
            FUN_004cfcd0();
            local_18 = (int *)FUN_004ce990();
          }
          else {
            FUN_004ce990();
            FUN_004ce990();
            iVar11 = FUN_004717c0();
            puVar10 = (undefined4 *)FUN_004ce990();
            if (*(int *)*puVar10 < iVar11) goto LAB_00451cfa;
            puVar10 = (undefined4 *)FUN_004ce990();
            local_18 = (int *)*puVar10;
          }
          puVar10 = (undefined4 *)FUN_004ce990();
          switch(*puVar10) {
          case 0:
            puVar10 = (undefined4 *)FUN_004ce990();
            *(int *)*puVar10 = *local_18;
            break;
          case 1:
            puVar10 = (undefined4 *)FUN_004ce990();
            *(int *)*puVar10 = *(int *)*puVar10 + *local_18;
            break;
          case 2:
            puVar10 = (undefined4 *)FUN_004ce990();
            *(int *)*puVar10 = *(int *)*puVar10 - *local_18;
            break;
          case 3:
            puVar10 = (undefined4 *)FUN_004ce990();
            *(int *)*puVar10 = *(int *)*puVar10 * *local_18;
            break;
          case 4:
            if (*local_18 != 0) {
              puVar10 = (undefined4 *)FUN_004ce990();
              *(int *)*puVar10 = *(int *)*puVar10 / *local_18;
            }
            break;
          case 5:
            if (*local_18 == 0) {
              puVar10 = (undefined4 *)FUN_004ce990();
              *(undefined4 *)*puVar10 = 1;
            }
            else {
              puVar10 = (undefined4 *)FUN_004ce990();
              *(int *)*puVar10 = *(int *)*puVar10 % *local_18;
            }
            break;
          case 6:
            puVar10 = (undefined4 *)FUN_004ce990();
            if (*(int *)*puVar10 < *local_18) {
              local_ec = *local_18;
            }
            else {
              puVar10 = (undefined4 *)FUN_004ce990();
              local_ec = *(int *)*puVar10;
            }
            puVar10 = (undefined4 *)FUN_004ce990();
            *(int *)*puVar10 = local_ec;
            break;
          case 7:
            puVar10 = (undefined4 *)FUN_004ce990();
            if (*local_18 < *(int *)*puVar10) {
              local_f0 = *local_18;
            }
            else {
              puVar10 = (undefined4 *)FUN_004ce990();
              local_f0 = *(int *)*puVar10;
            }
            puVar10 = (undefined4 *)FUN_004ce990();
            *(int *)*puVar10 = local_f0;
          }
        }
      }
      else {
        if (iVar11 != 420000) goto switchD_00450535_caseD_0;
        cVar1 = *(char *)(*(int *)(param_1 + 0x898) + 0x10);
        piVar8 = (int *)FUN_004ce990();
        if (*(int *)(param_1 + 0x38 + cVar1 * 4) == *piVar8) {
          *(undefined4 *)(param_1 + 0x38 + *(char *)(*(int *)(param_1 + 0x898) + 0x10) * 4) =
               0xffffff9c;
        }
        else {
          piVar8 = (int *)FUN_004ce990();
          *(int *)(param_1 + 8) = *piVar8 + -1;
        }
      }
    }
    else {
      if (iVar11 != 0x79951) goto switchD_00450535_caseD_0;
      pwVar12 = std::basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::back
                          ((basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>
                            *)(param_1 + 0x840));
      if (*(int *)pwVar12 < 1) {
        FUN_004ce1d0();
        FUN_004ce1d0();
      }
      else {
        FUN_004ce080();
        piVar8 = (int *)FUN_004ce990();
        *piVar8 = *piVar8 + -1;
        puVar10 = (undefined4 *)FUN_004ce990();
        *(undefined4 *)(param_1 + 8) = *puVar10;
      }
    }
    DAT_00a1434c = DAT_00a1434c + 1;
  } while( true );
}

