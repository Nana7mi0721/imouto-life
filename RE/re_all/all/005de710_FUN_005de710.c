
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall
FUN_005de710(undefined4 param_1,undefined4 param_2,int param_3,int *param_4,char param_5)

{
  float fVar1;
  bool bVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  int *piVar12;
  float *pfVar13;
  float *pfVar14;
  int local_54;
  float local_50;
  float local_4c;
  float local_40 [4];
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  
  iVar10 = *param_4;
  iVar11 = *(int *)(iVar10 + 8);
  piVar12 = (int *)param_4[2];
  iVar3 = param_4[0x2c];
  if (iVar3 == -1) {
    iVar3 = piVar12[0x67];
  }
  if ((param_5 == '\0') && ((*(int *)(*piVar12 + 8) == 1 || (*(int *)(*piVar12 + 8) == 2)))) {
    param_2 = 0;
  }
  FUN_0059a900(param_2);
  bVar2 = false;
  if (0 < *(int *)(param_4[2] + 0x58)) {
    iVar7 = *(int *)(param_4[2] + 100) * 0x74 + *(int *)(iVar11 + 0x1bc);
    fVar1 = *(float *)(iVar7 + 0x60) - 1.0;
    if (((((float)_DAT_007d6530 < fVar1) || (fVar1 < (float)_DAT_00801ee8)) ||
        (fVar1 = *(float *)(iVar7 + 100) - 1.0, (float)_DAT_007d6530 < fVar1)) ||
       (fVar1 < (float)_DAT_00801ee8)) {
      local_50 = *(float *)(iVar7 + 0x60);
      bVar2 = true;
      local_4c = *(float *)(iVar7 + 100);
    }
  }
  if (param_5 != '\0') {
    if ((*(int *)(iVar10 + 0x1a4) != 0) || (bVar2)) {
      local_40[0] = *(float *)(iVar10 + 0x1a8);
      local_40[1] = *(float *)(iVar10 + 0x1b8);
      local_40[2] = *(float *)(iVar10 + 0x1c8);
      local_40[3] = *(float *)(iVar10 + 0x1d8);
      local_30 = *(float *)(iVar10 + 0x1ac);
      local_2c = *(float *)(iVar10 + 0x1bc);
      local_28 = *(float *)(iVar10 + 0x1cc);
      local_24 = *(float *)(iVar10 + 0x1dc);
      if (bVar2) {
        local_40[0] = local_40[0] * local_50;
        local_2c = local_2c * local_4c;
      }
      pfVar14 = local_40;
    }
    else {
      pfVar14 = (float *)&DAT_00a054a0;
    }
    FUN_0059cb80(&DAT_00ddb600,0,2,0x58,pfVar14,2,0);
    *(undefined4 *)(param_3 + 0x30) = 0;
    piVar12 = (int *)(param_3 + 0x34);
    *piVar12 = 0;
    *(undefined4 *)(param_3 + 0x4c) = 0;
    *(undefined4 *)(param_3 + 100) = 0;
    *(undefined4 *)(param_3 + 0x7c) = 0;
    *(undefined4 *)(param_3 + 0x94) = 0;
    *(undefined4 *)(param_3 + 0xac) = 0;
    *(undefined4 *)(param_3 + 0xc4) = 0;
    *(undefined4 *)(param_3 + 0xdc) = 0;
    *(undefined4 *)(param_3 + 0xf4) = 0;
    *(undefined4 *)(param_3 + 0x10c) = 0;
    *(undefined4 *)(param_3 + 0x124) = 0;
    *(undefined4 *)(param_3 + 0x13c) = 0;
    *(undefined4 *)(param_3 + 0x38) = 0;
    *(undefined4 *)(param_3 + 0x3c) = 0;
    if (*(int *)(param_4[2] + 0x58) == 0) {
      if (DAT_00dda458 < 0) {
        FUN_00582be0();
        FUN_0059d430();
      }
      *(undefined4 *)(param_3 + 0x30) = 1;
      *piVar12 = DAT_00dda458;
    }
    else {
      *(undefined4 *)(param_3 + 0x30) = 1;
      piVar9 = (int *)(*(int *)(param_4[2] + 100) * 0x74 + *(int *)(iVar11 + 0x1bc));
      iVar10 = *piVar9;
      if (piVar9[0x11] == 0) {
        if (piVar9[0xe] == 0) {
          if (*(int *)(iVar10 + 0x50) == 0) {
            iVar10 = *(int *)(iVar10 + 0x48);
            goto LAB_005de91e;
          }
          *piVar12 = *(int *)(iVar10 + 0x54);
        }
        else {
          *piVar12 = piVar9[0xf];
        }
      }
      else {
        iVar10 = piVar9[0x12];
LAB_005de91e:
        *piVar12 = iVar10;
      }
      FUN_0059b0e0(piVar9[0x16],piVar9[0x17],3,0);
      FUN_0059a650(0,0x11,*(undefined4 *)(&DAT_00a0547c + piVar9[0x1a] * 0xc));
      FUN_0059a650(0,0x10,*(undefined4 *)(&DAT_00a05480 + piVar9[0x1a] * 0xc));
      FUN_0059a650(0,0x12,*(undefined4 *)(&DAT_00a05484 + piVar9[0x1a] * 0xc));
    }
    *(undefined4 *)(param_3 + 0x50) = 1;
    *(undefined4 *)(param_3 + 0x54) = 0;
    if (*(int *)(*(int *)(param_4[1] + 4) + 0x168) != 0) {
      *(undefined4 *)(param_3 + 0x30) = 2;
      piVar9 = (int *)(*(int *)(*(int *)(param_4[1] + 4) + 0x174) * 0x74 + *(int *)(iVar11 + 0x1bc))
      ;
      iVar10 = *piVar9;
      if (piVar9[0x11] == 0) {
        if (piVar9[0xe] == 0) {
          if (*(int *)(iVar10 + 0x50) == 0) {
            iVar10 = *(int *)(iVar10 + 0x48);
            goto LAB_005dea08;
          }
          *(undefined4 *)(param_3 + 0x4c) = *(undefined4 *)(iVar10 + 0x54);
        }
        else {
          *(int *)(param_3 + 0x4c) = piVar9[0xf];
        }
      }
      else {
        iVar10 = piVar9[0x12];
LAB_005dea08:
        *(int *)(param_3 + 0x4c) = iVar10;
      }
      FUN_0059b0e0(piVar9[0x16],piVar9[0x17],3,1);
      FUN_0059a650(1,0x11,*(undefined4 *)(&DAT_00a0547c + piVar9[0x1a] * 0xc));
      FUN_0059a650(1,0x10,*(undefined4 *)(&DAT_00a05480 + piVar9[0x1a] * 0xc));
      FUN_0059a650(1,0x12,*(undefined4 *)(&DAT_00a05484 + piVar9[0x1a] * 0xc));
    }
    *(undefined4 *)(param_3 + 0x68) = 2;
    *(undefined4 *)(param_3 + 0x6c) = 0;
    if (((int *)param_4[2])[0x37] == 0) {
      iVar10 = *(int *)(*(int *)param_4[2] + 8);
      if ((iVar10 == 1) || (iVar10 == 2)) {
        if (DAT_00dda458 < 0) {
          FUN_00582be0();
          FUN_0059d430();
        }
        *(int *)(param_3 + 100) = DAT_00dda458;
      }
    }
    else {
      *(undefined4 *)(param_3 + 0x30) = 3;
      piVar9 = (int *)(*(int *)(param_4[2] + 0xe8) * 0x74 + *(int *)(iVar11 + 0x1bc));
      iVar10 = *piVar9;
      if (piVar9[0x11] == 0) {
        if (piVar9[0xe] == 0) {
          if (*(int *)(iVar10 + 0x50) == 0) {
            iVar10 = *(int *)(iVar10 + 0x48);
            goto LAB_005deaca;
          }
          *(undefined4 *)(param_3 + 100) = *(undefined4 *)(iVar10 + 0x54);
        }
        else {
          *(int *)(param_3 + 100) = piVar9[0xf];
        }
      }
      else {
        iVar10 = piVar9[0x12];
LAB_005deaca:
        *(int *)(param_3 + 100) = iVar10;
      }
      FUN_0059b0e0(piVar9[0x16],piVar9[0x17],3,2);
      FUN_0059a650(2,0x11,*(undefined4 *)(&DAT_00a0547c + piVar9[0x1a] * 0xc));
      FUN_0059a650(2,0x10,*(undefined4 *)(&DAT_00a05480 + piVar9[0x1a] * 0xc));
      FUN_0059a650(2,0x12,*(undefined4 *)(&DAT_00a05484 + piVar9[0x1a] * 0xc));
    }
    if ((*(int *)(*(int *)param_4[2] + 8) == 1) || (*(int *)(*(int *)param_4[2] + 8) == 2)) {
      *(undefined4 *)(param_3 + 0x30) = 5;
      iVar10 = ((int *)param_4[2])[0x58];
      if (iVar10 < 0) {
        if (*(int *)(*(int *)param_4[2] + 8) == 1) {
          uVar4 = FUN_00582b00(iVar10);
          *(undefined4 *)(param_3 + 0x7c) = uVar4;
          FUN_0059d430();
        }
        else {
          *(int *)(param_3 + 0x7c) = DAT_00dda458;
        }
      }
      else {
        piVar9 = (int *)(iVar10 * 0x74 + *(int *)(iVar11 + 0x1bc));
        iVar10 = *piVar9;
        if (piVar9[0x11] == 0) {
          if (piVar9[0xe] == 0) {
            if (*(int *)(iVar10 + 0x50) == 0) {
              iVar10 = *(int *)(iVar10 + 0x48);
              goto LAB_005debc1;
            }
            *(undefined4 *)(param_3 + 0x7c) = *(undefined4 *)(iVar10 + 0x54);
          }
          else {
            *(int *)(param_3 + 0x7c) = piVar9[0xf];
          }
        }
        else {
          iVar10 = piVar9[0x12];
LAB_005debc1:
          *(int *)(param_3 + 0x7c) = iVar10;
        }
        FUN_0059b0e0(piVar9[0x16],piVar9[0x17],3,3);
        FUN_0059a650(3,0x11,*(undefined4 *)(&DAT_00a0547c + piVar9[0x1a] * 0xc));
        FUN_0059a650(3,0x10,*(undefined4 *)(&DAT_00a05480 + piVar9[0x1a] * 0xc));
        FUN_0059a650(3,0x12,*(undefined4 *)(&DAT_00a05484 + piVar9[0x1a] * 0xc));
      }
      *(undefined4 *)(param_3 + 0x80) = 3;
      *(undefined4 *)(param_3 + 0x84) = 0;
      iVar10 = *(int *)(param_4[2] + 0x164);
      if (iVar10 < 0) {
        uVar4 = FUN_00582b00(iVar10);
        *(undefined4 *)(param_3 + 0x94) = uVar4;
        FUN_0059d430();
      }
      else {
        piVar9 = (int *)(iVar10 * 0x74 + *(int *)(iVar11 + 0x1bc));
        iVar10 = *piVar9;
        if (piVar9[0x11] == 0) {
          if (piVar9[0xe] == 0) {
            if (*(int *)(iVar10 + 0x50) == 0) {
              iVar10 = *(int *)(iVar10 + 0x48);
              goto LAB_005dec98;
            }
            *(undefined4 *)(param_3 + 0x94) = *(undefined4 *)(iVar10 + 0x54);
          }
          else {
            *(int *)(param_3 + 0x94) = piVar9[0xf];
          }
        }
        else {
          iVar10 = piVar9[0x12];
LAB_005dec98:
          *(int *)(param_3 + 0x94) = iVar10;
        }
        FUN_0059b0e0(piVar9[0x16],piVar9[0x17],3,4);
        FUN_0059a650(4,0x11,*(undefined4 *)(&DAT_00a0547c + piVar9[0x1a] * 0xc));
        FUN_0059a650(4,0x10,*(undefined4 *)(&DAT_00a05480 + piVar9[0x1a] * 0xc));
        FUN_0059a650(4,0x12,*(undefined4 *)(&DAT_00a05484 + piVar9[0x1a] * 0xc));
      }
      *(undefined4 *)(param_3 + 0x98) = 4;
      *(undefined4 *)(param_3 + 0x9c) = 0;
      if (-1 < *(int *)(param_4[2] + 0x168)) {
        if (DAT_00dda458 < 0) {
          FUN_00582be0();
          FUN_0059d430();
        }
        *(undefined4 *)(param_3 + 0x30) = 6;
        piVar9 = (int *)(*(int *)(param_4[2] + 0x168) * 0x74 + *(int *)(iVar11 + 0x1bc));
        iVar10 = *piVar9;
        if (piVar9[0x11] == 0) {
          if ((piVar9[0xe] == 0) || (piVar9[0x10] != 0)) {
            if (*(int *)(iVar10 + 0x50) == 0) {
              if (*(int *)(iVar10 + 0x4c) == 0) {
                *(undefined4 *)(param_3 + 0xac) = *(undefined4 *)(iVar10 + 0x48);
              }
              else {
                if (*(int *)(param_4[2] + 0x174) != 2) {
                  uVar4 = DAT_00dda45c;
                  goto LAB_005deda9;
                }
                *(int *)(param_3 + 0xac) = DAT_00dda458;
              }
            }
            else {
              uVar4 = *(undefined4 *)(iVar10 + 0x54);
LAB_005deda9:
              *(undefined4 *)(param_3 + 0xac) = uVar4;
            }
          }
          else {
            *(int *)(param_3 + 0xac) = piVar9[0xf];
          }
        }
        else {
          *(int *)(param_3 + 0xac) = piVar9[0x12];
        }
        FUN_0059b0e0(piVar9[0x16],piVar9[0x17],3,5);
        FUN_0059a650(5,0x11,*(undefined4 *)(&DAT_00a0547c + piVar9[0x1a] * 0xc));
        FUN_0059a650(5,0x10,*(undefined4 *)(&DAT_00a05480 + piVar9[0x1a] * 0xc));
        FUN_0059a650(5,0x12,*(undefined4 *)(&DAT_00a05484 + piVar9[0x1a] * 0xc));
        *(undefined4 *)(param_3 + 0xb0) = 5;
        *(undefined4 *)(param_3 + 0xb4) = 0;
      }
      FUN_0059a650(6,0x11,2);
      FUN_0059a650(6,0x10,2);
      FUN_0059a650(6,0x12,2);
      FUN_0059b0e0(3,3,3,6);
      iVar10 = param_4[2];
      local_40[0] = *(float *)(iVar10 + 0x180);
      local_40[1] = *(float *)(iVar10 + 0x184);
      local_40[2] = *(float *)(iVar10 + 0x188);
      local_40[3] = *(float *)(iVar10 + 0x18c);
      local_30 = 1.0 / *(float *)(iVar10 + 0x178);
      local_2c = 1.0 / *(float *)(iVar10 + 0x178);
      local_28 = 1.0 / *(float *)(iVar10 + 0x178);
      local_24 = 1.0 / *(float *)(iVar10 + 0x178);
      FUN_0059cb80(&DAT_00ddb600,3,2,6,local_40,2,0);
    }
    *(undefined4 *)(param_3 + 0xe0) = 0;
    *(undefined4 *)(param_3 + 0xe4) = 0;
    if (*(int *)(param_4[2] + 0x58) < 2) goto LAB_005def8c;
    *(undefined4 *)(param_3 + 0x30) = 8;
    piVar9 = (int *)(*(int *)(param_4[2] + 0x74) * 0x74 + *(int *)(iVar11 + 0x1bc));
    iVar10 = *piVar9;
    if (piVar9[0x11] == 0) {
      if (piVar9[0xe] == 0) {
        if (*(int *)(iVar10 + 0x50) == 0) {
          iVar10 = *(int *)(iVar10 + 0x48);
          goto LAB_005def2d;
        }
        *(undefined4 *)(param_3 + 0xdc) = *(undefined4 *)(iVar10 + 0x54);
      }
      else {
        *(int *)(param_3 + 0xdc) = piVar9[0xf];
      }
    }
    else {
      iVar10 = piVar9[0x12];
LAB_005def2d:
      *(int *)(param_3 + 0xdc) = iVar10;
    }
    FUN_0059b0e0(piVar9[0x16],piVar9[0x17],3,7);
    FUN_0059a650(7,0x11,*(undefined4 *)(&DAT_00a0547c + piVar9[0x1a] * 0xc));
    FUN_0059a650(7,0x10,*(undefined4 *)(&DAT_00a05480 + piVar9[0x1a] * 0xc));
    FUN_0059a650(7,0x12,*(undefined4 *)(&DAT_00a05484 + piVar9[0x1a] * 0xc));
LAB_005def8c:
    iVar10 = 8;
    _param_5 = &DAT_00a380f8;
    piVar9 = (int *)(param_3 + 0xf4);
    local_54 = 3;
    do {
      piVar9[1] = 0;
      piVar9[2] = 0;
      if (*_param_5 < 1) {
        *piVar9 = 0;
      }
      else {
        *piVar9 = *_param_5;
        FUN_0059b0e0(3,3,3,iVar10);
        FUN_0059a650(iVar10,0x11,2);
        FUN_0059a650(iVar10,0x10,2);
        FUN_0059a650(iVar10,0x12,2);
      }
      _param_5 = _param_5 + 1;
      piVar9 = piVar9 + 6;
      iVar10 = iVar10 + 1;
      local_54 = local_54 + -1;
    } while (local_54 != 0);
    *(undefined4 *)(param_3 + 0x30) = 0xb;
    if (DAT_00dccde4 != 0) {
      iVar10 = -1;
      iVar11 = 0;
      do {
        if ((&DAT_00a38d78)[iVar11] == 0) {
          if (*(int *)(param_3 + 0x30) <= iVar11) {
            *piVar12 = 0;
            piVar12[1] = 0;
            piVar12[2] = 0;
          }
        }
        else {
          *piVar12 = (&DAT_00a38d78)[iVar11];
          FUN_0059b0e0((&DAT_00a37fe0)[iVar11],(&DAT_00a38020)[iVar11],(&DAT_00a38060)[iVar11],
                       iVar11);
          FUN_0059a650(iVar11,0x11,*(undefined4 *)(&DAT_00a0547c + DAT_00a380bc * 0xc));
          FUN_0059a650(iVar11,0x10,*(undefined4 *)(&DAT_00a05480 + DAT_00a380bc * 0xc));
          FUN_0059a650(iVar11,0x12,*(undefined4 *)(&DAT_00a05484 + DAT_00a380bc * 0xc));
          iVar10 = iVar11;
        }
        iVar11 = iVar11 + 1;
        piVar12 = piVar12 + 6;
      } while (iVar11 < 0x10);
      if ((0 < iVar10) && (*(int *)(param_3 + 0x30) < iVar10 + 1)) {
        *(int *)(param_3 + 0x30) = iVar10 + 1;
      }
    }
    FUN_005a7d70(param_3,1,1,1);
    if ((*(int *)(*(int *)param_4[2] + 8) == 1) && (*(int *)(param_3 + 0xc4) == 0)) {
      FUN_005d3a90(6,DAT_00ddb368);
      _DAT_00e79754 = DAT_00ddb368;
    }
    FUN_0059b980();
    return;
  }
  if (bVar2) {
    if (*(int *)(iVar10 + 0x1a4) == 0) {
      FUN_00585060(local_40);
    }
    else {
      pfVar14 = (float *)(iVar10 + 0x1a8);
      pfVar13 = local_40;
      for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
        *pfVar13 = *pfVar14;
        pfVar14 = pfVar14 + 1;
        pfVar13 = pfVar13 + 1;
      }
    }
    local_40[0] = local_40[0] * local_50;
    local_2c = local_2c * local_4c;
    FUN_00519a00(1,local_40,0);
    FUN_00519a00(1,local_40,1);
    FUN_00519a00(1,local_40,2);
    FUN_00519a00(1,local_40,3);
  }
  else {
    iVar7 = iVar10 + 0x1a8;
    FUN_00519a00(*(undefined4 *)(iVar10 + 0x1a4),iVar7,0);
    FUN_00519a00(*(undefined4 *)(iVar10 + 0x1a4),iVar7,1);
    FUN_00519a00(*(undefined4 *)(iVar10 + 0x1a4),iVar7,2);
    FUN_00519a00(*(undefined4 *)(iVar10 + 0x1a4),iVar7,3);
  }
  *(undefined4 *)(param_3 + 0x34) = 0;
  if (*(int *)(param_4[2] + 0x58) == 0) {
    if (DAT_00dda458 < 0) {
      FUN_00582be0();
      FUN_0059d430();
    }
    *(int *)(param_3 + 0x34) = DAT_00dda458;
  }
  else {
    piVar9 = (int *)(*(int *)(param_4[2] + 100) * 0x74 + *(int *)(iVar11 + 0x1bc));
    iVar10 = *piVar9;
    if (piVar9[0x11] == 0) {
      if (piVar9[0xe] == 0) {
        if (*(int *)(iVar10 + 0x50) == 0) {
          iVar10 = *(int *)(iVar10 + 0x48);
          goto LAB_005df235;
        }
        *(undefined4 *)(param_3 + 0x34) = *(undefined4 *)(iVar10 + 0x54);
      }
      else {
        *(int *)(param_3 + 0x34) = piVar9[0xf];
      }
    }
    else {
      iVar10 = piVar9[0x12];
LAB_005df235:
      *(int *)(param_3 + 0x34) = iVar10;
    }
    FUN_0059b0e0(piVar9[0x16],piVar9[0x17],3,0);
    FUN_0059a650(0,0x11,*(undefined4 *)(&DAT_00a0547c + piVar9[0x1a] * 0xc));
    FUN_0059a650(0,0x10,*(undefined4 *)(&DAT_00a05480 + piVar9[0x1a] * 0xc));
    FUN_0059a650(0,0x12,*(undefined4 *)(&DAT_00a05484 + piVar9[0x1a] * 0xc));
  }
  *(undefined4 *)(param_3 + 0x38) = 0;
  *(undefined4 *)(param_3 + 0x3c) = 0;
  *(undefined2 *)(param_3 + 0x46) = 2;
  *(undefined2 *)(param_3 + 0x48) = 0;
  *(undefined2 *)(param_3 + 0x4a) = 4;
  *(undefined2 *)(param_3 + 0x40) = 2;
  *(undefined2 *)(param_3 + 0x42) = 0;
  *(undefined2 *)(param_3 + 0x44) = 4;
  iVar10 = 1;
  if (*(int *)(*piVar12 + 8) == 1) {
LAB_005df562:
    if (*(int *)(param_4[2] + 0x160) == -1) {
      piVar9 = (int *)(param_3 + 0x34 + iVar10 * 0x18);
      iVar7 = FUN_00582b00(0xffffffff);
      *piVar9 = iVar7;
      FUN_0059d430();
    }
    else {
      piVar5 = (int *)(*(int *)(param_4[2] + 0x160) * 0x74 + *(int *)(iVar11 + 0x1bc));
      iVar7 = *piVar5;
      if (piVar5[0x11] == 0) {
        if (piVar5[0xe] == 0) {
          if (*(int *)(iVar7 + 0x50) == 0) {
            iVar7 = *(int *)(iVar7 + 0x48);
          }
          else {
            iVar7 = *(int *)(iVar7 + 0x54);
          }
        }
        else {
          iVar7 = piVar5[0xf];
        }
        piVar9 = (int *)(param_3 + 0x34 + iVar10 * 0x18);
        *piVar9 = iVar7;
      }
      else {
        piVar9 = (int *)(param_3 + 0x34 + iVar10 * 0x18);
        *piVar9 = piVar5[0x12];
      }
      FUN_0059b0e0(3,3,3,iVar10);
      FUN_0059a650(iVar10,0x11,*(undefined4 *)(&DAT_00a0547c + piVar5[0x1a] * 0xc));
      FUN_0059a650(iVar10,0x10,*(undefined4 *)(&DAT_00a05480 + piVar5[0x1a] * 0xc));
      FUN_0059a650(iVar10,0x12,*(undefined4 *)(&DAT_00a05484 + piVar5[0x1a] * 0xc));
    }
    piVar9[1] = 1;
    piVar9[2] = 0;
    if (*(int *)(param_4[2] + 0x16c) == 0) {
      *(undefined2 *)((int)piVar9 + 0x16) = 0xd;
LAB_005df657:
      *(undefined2 *)(piVar9 + 4) = 2;
      *(undefined2 *)((int)piVar9 + 0xe) = 1;
      *(undefined2 *)(piVar9 + 3) = 1;
      *(undefined2 *)(piVar9 + 5) = 1;
      *(undefined2 *)((int)piVar9 + 0x12) = 2;
    }
    else if (*(int *)(param_4[2] + 0x16c) == 2) {
      *(undefined2 *)((int)piVar9 + 0x16) = 4;
      goto LAB_005df657;
    }
    iVar7 = iVar10 + 1;
    if (*(int *)(*piVar12 + 8) == 1) {
      if ((DAT_00ddb4b8 == 1) || (iVar8 = param_4[2], *(int *)(iVar8 + 0x170) != 1)) {
        iVar8 = param_4[2];
        if (*(int *)(iVar8 + 0x164) == -1) goto LAB_005df779;
        piVar12 = (int *)(*(int *)(iVar8 + 0x164) * 0x74 + *(int *)(iVar11 + 0x1bc));
        iVar11 = *piVar12;
        if (piVar12[0x11] == 0) {
          if (piVar12[0xe] == 0) {
            if (*(int *)(iVar11 + 0x50) == 0) {
              iVar11 = *(int *)(iVar11 + 0x48);
            }
            else {
              iVar11 = *(int *)(iVar11 + 0x54);
            }
          }
          else {
            iVar11 = piVar12[0xf];
          }
          piVar9 = (int *)(param_3 + 0x34 + iVar7 * 0x18);
          *piVar9 = iVar11;
        }
        else {
          piVar9 = (int *)(param_3 + 0x34 + iVar7 * 0x18);
          *piVar9 = piVar12[0x12];
        }
        FUN_0059b0e0(3,3,3,iVar7);
        FUN_0059a650(iVar7,0x11,*(undefined4 *)(&DAT_00a0547c + piVar12[0x1a] * 0xc));
        FUN_0059a650(iVar7,0x10,*(undefined4 *)(&DAT_00a05480 + piVar12[0x1a] * 0xc));
        FUN_0059a650(iVar7,0x12,*(undefined4 *)(&DAT_00a05484 + piVar12[0x1a] * 0xc));
      }
      else {
LAB_005df779:
        piVar9 = (int *)(param_3 + 0x34 + iVar7 * 0x18);
        iVar11 = FUN_00582b00(*(undefined4 *)(iVar8 + 0x164));
        *piVar9 = iVar11;
        FUN_0059d430();
      }
      piVar9[1] = 2;
      if (DAT_00ddb4b8 != 0) {
        if (*(int *)(param_4[2] + 0x170) == 0) {
          *(undefined2 *)(piVar9 + 5) = 4;
          *(undefined2 *)((int)piVar9 + 0x16) = 4;
          piVar9[-4] = 1;
          piVar9[2] = 0;
          *(undefined2 *)((int)piVar9 + 0x12) = 2;
          *(undefined2 *)(piVar9 + 3) = 1;
          *(undefined2 *)((int)piVar9 + 0xe) = 1;
          *(undefined2 *)(piVar9 + 4) = 2;
          puVar6 = (undefined4 *)(param_3 + 0x34 + (iVar10 + 2) * 0x18);
          *(undefined2 *)((int)puVar6 + 0x12) = 1;
          *(undefined2 *)(puVar6 + 5) = 5;
          *(undefined2 *)((int)puVar6 + 0x16) = 0x10;
          iVar7 = iVar10 + 3;
        }
        else {
          if (*(int *)(param_4[2] + 0x170) != 1) goto LAB_005df8b3;
          *(undefined2 *)(piVar9 + 5) = 4;
          *(undefined2 *)((int)piVar9 + 0x16) = 4;
          piVar9[-4] = 1;
          piVar9[2] = 0;
          *(undefined2 *)((int)piVar9 + 0x12) = 2;
          *(undefined2 *)(piVar9 + 3) = 1;
          *(undefined2 *)((int)piVar9 + 0xe) = 1;
          *(undefined2 *)(piVar9 + 4) = 2;
          iVar7 = iVar10 + 2;
          puVar6 = (undefined4 *)(param_3 + 0x34 + iVar7 * 0x18);
          *(undefined2 *)((int)puVar6 + 0x12) = 5;
          *(undefined2 *)(puVar6 + 5) = 1;
          *(undefined2 *)((int)puVar6 + 0x16) = 7;
        }
        *(undefined2 *)(puVar6 + 4) = 2;
        *(undefined2 *)(puVar6 + 3) = 5;
        puVar6[1] = 0;
        goto LAB_005df8aa;
      }
      piVar9[2] = 0;
      if (*(int *)(param_4[2] + 0x170) == 0) {
        *(undefined2 *)((int)piVar9 + 0x12) = 2;
        *(undefined2 *)(piVar9 + 5) = 1;
        *(undefined2 *)((int)piVar9 + 0x16) = 0xd;
        *(undefined2 *)(piVar9 + 3) = 1;
        *(undefined2 *)((int)piVar9 + 0xe) = 1;
        *(undefined2 *)(piVar9 + 4) = 2;
      }
      else if (*(int *)(param_4[2] + 0x170) == 1) {
        *(undefined2 *)((int)piVar9 + 0x12) = 2;
        *(undefined2 *)(piVar9 + 5) = 1;
        *(undefined2 *)((int)piVar9 + 0x16) = 7;
        *(undefined2 *)(piVar9 + 3) = 1;
        *(undefined2 *)((int)piVar9 + 0xe) = 1;
        *(undefined2 *)(piVar9 + 4) = 2;
      }
    }
    else {
      if (*(int *)(*piVar12 + 8) != 2) goto LAB_005df8b5;
      puVar6 = (undefined4 *)(param_3 + 0x34 + iVar7 * 0x18);
      puVar6[1] = 0xffffffff;
      *(undefined2 *)((int)puVar6 + 0x12) = 4;
      *(undefined2 *)(puVar6 + 5) = 1;
      *(undefined2 *)((int)puVar6 + 0x16) = 7;
      *(undefined2 *)(puVar6 + 3) = 1;
      *(undefined2 *)(puVar6 + 4) = 2;
LAB_005df8aa:
      *(undefined2 *)((int)puVar6 + 0xe) = 1;
      puVar6[2] = 0;
      *puVar6 = 0;
    }
LAB_005df8b3:
    iVar7 = iVar7 + 1;
  }
  else {
    if (*(int *)(*piVar12 + 8) == 2) {
      if ((-1 < piVar12[0x5a]) && (*(int *)(param_4[2] + 0x174) != 3)) {
        piVar9 = (int *)(*(int *)(param_4[2] + 0x168) * 0x74 + *(int *)(iVar11 + 0x1bc));
        iVar10 = *piVar9;
        if (piVar9[0x11] == 0) {
          if ((piVar9[0xe] == 0) || (piVar9[0x10] != 0)) {
            if (*(int *)(iVar10 + 0x50) == 0) {
              if (*(int *)(iVar10 + 0x4c) == 0) {
                *(undefined4 *)(param_3 + 0x4c) = *(undefined4 *)(iVar10 + 0x48);
              }
              else {
                if (piVar12[0x5d] != 2) {
                  uVar4 = DAT_00dda45c;
                  goto LAB_005df49f;
                }
                *(int *)(param_3 + 0x4c) = DAT_00dda458;
              }
            }
            else {
              uVar4 = *(undefined4 *)(iVar10 + 0x54);
LAB_005df49f:
              *(undefined4 *)(param_3 + 0x4c) = uVar4;
            }
          }
          else {
            *(int *)(param_3 + 0x4c) = piVar9[0x12];
          }
        }
        else {
          *(int *)(param_3 + 0x4c) = piVar9[0x12];
        }
        FUN_0059b0e0(3,3,3,1);
        FUN_0059a650(1,0x11,*(undefined4 *)(&DAT_00a0547c + piVar9[0x1a] * 0xc));
        FUN_0059a650(1,0x10,*(undefined4 *)(&DAT_00a05480 + piVar9[0x1a] * 0xc));
        FUN_0059a650(1,0x12,*(undefined4 *)(&DAT_00a05484 + piVar9[0x1a] * 0xc));
        *(undefined4 *)(param_3 + 0x50) = 2;
        *(undefined4 *)(param_3 + 0x54) = 0;
        if (*(int *)(param_4[2] + 0x174) == 1) {
          *(undefined2 *)(param_3 + 0x5e) = 2;
          *(undefined2 *)(param_3 + 0x60) = 1;
          *(undefined2 *)(param_3 + 0x62) = 7;
          *(undefined2 *)(param_3 + 0x58) = 1;
          *(undefined2 *)(param_3 + 0x5a) = 1;
          *(undefined2 *)(param_3 + 0x5c) = 2;
        }
        else if (*(int *)(param_4[2] + 0x174) == 2) {
          *(undefined2 *)(param_3 + 0x5e) = 2;
          *(undefined2 *)(param_3 + 0x60) = 1;
          *(undefined2 *)(param_3 + 0x62) = 4;
          *(undefined2 *)(param_3 + 0x58) = 1;
          *(undefined2 *)(param_3 + 0x5a) = 1;
          *(undefined2 *)(param_3 + 0x5c) = 2;
        }
        iVar10 = 2;
      }
      goto LAB_005df562;
    }
    iVar7 = iVar10;
    if (1 < *(int *)(param_4[2] + 0x58)) {
      piVar12 = (int *)(*(int *)(param_4[2] + 0x74) * 0x74 + *(int *)(iVar11 + 0x1bc));
      iVar10 = *piVar12;
      if (piVar12[0x11] == 0) {
        if (piVar12[0xe] == 0) {
          if (*(int *)(iVar10 + 0x50) == 0) {
            iVar10 = *(int *)(iVar10 + 0x48);
            goto LAB_005df333;
          }
          *(undefined4 *)(param_3 + 0x4c) = *(undefined4 *)(iVar10 + 0x54);
        }
        else {
          *(int *)(param_3 + 0x4c) = piVar12[0xf];
        }
      }
      else {
        iVar10 = piVar12[0x12];
LAB_005df333:
        *(int *)(param_3 + 0x4c) = iVar10;
      }
      FUN_0059b0e0(piVar12[0x16],piVar12[0x17],3,1);
      FUN_0059a650(1,0x11,*(undefined4 *)(&DAT_00a0547c + piVar12[0x1a] * 0xc));
      FUN_0059a650(1,0x10,*(undefined4 *)(&DAT_00a05480 + piVar12[0x1a] * 0xc));
      FUN_0059a650(1,0x12,*(undefined4 *)(&DAT_00a05484 + piVar12[0x1a] * 0xc));
      iVar7 = 2;
      *(undefined4 *)(param_3 + 0x50) = 1;
      *(undefined4 *)(param_3 + 0x54) = 0;
      *(undefined2 *)(param_3 + 0x5e) = 2;
      *(undefined2 *)(param_3 + 0x60) = 1;
      iVar10 = *(int *)(param_4[2] + 0x78);
      if (iVar10 == 1) {
        *(undefined2 *)(param_3 + 0x62) = 7;
        *(undefined2 *)(param_3 + 0x58) = 1;
        *(undefined2 *)(param_3 + 0x5a) = 1;
        *(undefined2 *)(param_3 + 0x5c) = 2;
      }
      else if (iVar10 == 2) {
        *(undefined2 *)(param_3 + 0x62) = 4;
        *(undefined2 *)(param_3 + 0x58) = 1;
        *(undefined2 *)(param_3 + 0x5a) = 1;
        *(undefined2 *)(param_3 + 0x5c) = 2;
      }
      else if (iVar10 == 3) {
        *(undefined2 *)(param_3 + 0x62) = 5;
        *(undefined2 *)(param_3 + 0x58) = 1;
        *(undefined2 *)(param_3 + 0x5a) = 1;
        *(undefined2 *)(param_3 + 0x5c) = 2;
      }
      else {
        *(undefined2 *)(param_3 + 0x62) = 0xd;
        *(undefined2 *)(param_3 + 0x58) = 1;
        *(undefined2 *)(param_3 + 0x5a) = 1;
        *(undefined2 *)(param_3 + 0x5c) = 2;
      }
    }
  }
LAB_005df8b5:
  puVar6 = (undefined4 *)(param_3 + 0x34 + iVar7 * 0x18);
  puVar6[2] = 0;
  if (iVar3 == 0xb) {
    if (*(int *)(param_3 + 0x14) == -1) goto LAB_005df914;
    *(undefined2 *)(puVar6 + 5) = 3;
    *(undefined2 *)((int)puVar6 + 0x16) = 0xe;
    *(undefined2 *)((int)puVar6 + 0xe) = 0;
    *(undefined2 *)(puVar6 + 4) = 2;
  }
  else {
    if (*(int *)(param_3 + 0x14) == -1) goto LAB_005df914;
    *(undefined2 *)(puVar6 + 5) = 0;
    *(undefined2 *)((int)puVar6 + 0x16) = 2;
    *(undefined2 *)((int)puVar6 + 0xe) = 3;
    *(undefined2 *)(puVar6 + 4) = 4;
  }
  iVar7 = iVar7 + 1;
  *(undefined2 *)(puVar6 + 3) = 1;
  *(undefined2 *)((int)puVar6 + 0x12) = 1;
  puVar6[1] = 0;
  *puVar6 = 0;
LAB_005df914:
  puVar6 = (undefined4 *)(param_3 + 0x34 + iVar7 * 0x18);
  *puVar6 = 0;
  puVar6[1] = 0;
  puVar6[2] = 0;
  *(undefined2 *)((int)puVar6 + 0x12) = 2;
  *(undefined2 *)(puVar6 + 5) = 0;
  *(undefined2 *)((int)puVar6 + 0x16) = 1;
  *(undefined2 *)(puVar6 + 3) = 2;
  *(undefined2 *)((int)puVar6 + 0xe) = 0;
  *(undefined2 *)(puVar6 + 4) = 1;
  *(int *)(param_3 + 0x30) = iVar7 + 1;
  FUN_005a7d70(param_3,0,1,1);
  return;
}

