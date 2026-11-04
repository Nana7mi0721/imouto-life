
undefined4
FUN_005dadd0(undefined4 param_1,uint *param_2,undefined4 *param_3,int param_4,undefined4 param_5)

{
  uint *puVar1;
  uint *puVar2;
  undefined4 *puVar3;
  short sVar4;
  int *piVar5;
  int in_EAX;
  int iVar6;
  short *psVar7;
  LPCVOID lpBuffer;
  uint uVar8;
  int iVar9;
  DWORD nNumberOfBytesToWrite;
  undefined8 uVar10;
  undefined8 *puVar11;
  undefined4 uVar12;
  undefined1 *puVar13;
  undefined8 uStack_264;
  uint uStack_25c;
  uint auStack_258 [2];
  DWORD DStack_250;
  undefined1 auStack_24c [16];
  undefined4 auStack_23c [2];
  undefined4 uStack_234;
  undefined4 uStack_20c;
  undefined4 uStack_204;
  
  *(undefined4 *)(in_EAX + 0x510) = 0;
  *(undefined4 *)(in_EAX + 0xd4) = 0;
  *(undefined4 *)(in_EAX + 0x530) = 0;
  *(undefined4 *)(in_EAX + 0x534) = 0;
  *(undefined4 *)(in_EAX + 0x538) = 0;
  *(undefined4 *)(in_EAX + 0x53c) = 0;
  *(undefined4 *)(in_EAX + 0xd0) = 0;
  FUN_0056d380(in_EAX + 0x540,0,0x10);
  FUN_0056d380(in_EAX + 0x550,0);
  *(undefined4 *)(in_EAX + 0x5bc) = 0;
  *(undefined4 *)(in_EAX + 0x5f8) = 0;
  *(undefined4 *)(in_EAX + 0x5fc) = 0;
  *(undefined4 *)(in_EAX + 0x590) = 0xffffffff;
  *(undefined4 *)(in_EAX + 0x594) = 0xffffffff;
  *(undefined4 *)(in_EAX + 0x598) = 0xffffffff;
  if ((((DAT_00aba204 == 0) || (DAT_00aba224 == 0)) || (DAT_00aba208 == (code *)0x0)) ||
     ((DAT_00aba228 == (code *)0x0 || (DAT_00aba210 == (code *)0x0)))) {
    return 0xffffffff;
  }
  if (DAT_00ca3a30 == 0) {
    DAT_00ca3a30 = 1;
    iVar6 = (*DAT_00aba208)(0x20070,0);
    if (iVar6 != 0) {
      FUN_0056cf70();
      goto LAB_005db3fa;
    }
  }
  psVar7 = (short *)(in_EAX + 0x644);
  FUN_0056cf70();
  sVar4 = *psVar7;
  while (sVar4 != 0) {
    if (*psVar7 == 0x2f) {
      *psVar7 = 0x5c;
    }
    psVar7 = psVar7 + 1;
    sVar4 = *psVar7;
  }
  iVar6 = (*DAT_00aba228)();
  if (iVar6 != 0) {
    if (*(int *)(in_EAX + 0x640) == 1) goto LAB_005db3fa;
    iVar6 = thunk_FUN_00572540(param_1,0,1,0);
    if (iVar6 == 0) goto LAB_005db3fa;
    FUN_0052c610(iVar6,0,0,2);
    auStack_258[0] = thunk_FUN_00571dd0(iVar6);
    FUN_0052c610(iVar6,0,0,0);
    lpBuffer = (LPCVOID)FUN_0056e030(0x100000,
                                     "..\\..\\..\\..\\Source\\Library\\Main\\Windows\\DxMovieWin.cpp"
                                     ,0x111);
    if (lpBuffer == (LPCVOID)0x0) {
      thunk_FUN_00571d20(iVar6);
      goto LAB_005db3fa;
    }
    uStack_264._0_4_ = (undefined4 *)FUN_00594cb0(in_EAX + 0x644,0xc00);
    if ((undefined4 *)uStack_264 == (HANDLE)0x0) {
      thunk_FUN_00571d20(iVar6);
      FUN_0056e1d0(lpBuffer);
      goto LAB_005db3fa;
    }
    *(undefined4 *)(in_EAX + 0x640) = 1;
    uStack_25c = 0;
    if (auStack_258[0] != 0) {
      do {
        nNumberOfBytesToWrite = uStack_25c - auStack_258[0];
        if (0x100000 < nNumberOfBytesToWrite) {
          nNumberOfBytesToWrite = 0x100000;
        }
        thunk_FUN_00571e60(lpBuffer,nNumberOfBytesToWrite,1,iVar6);
        WriteFile((undefined4 *)uStack_264,lpBuffer,nNumberOfBytesToWrite,&DStack_250,
                  (LPOVERLAPPED)0x0);
      } while ((nNumberOfBytesToWrite == DStack_250) &&
              (uStack_25c = uStack_25c + nNumberOfBytesToWrite, uStack_25c < auStack_258[0]));
    }
    thunk_FUN_00571d20(iVar6);
    CloseHandle((undefined4 *)uStack_264);
    FUN_0056e1d0(lpBuffer);
    iVar6 = (*DAT_00aba228)();
    if (iVar6 != 0) {
      DeleteFileW((LPCWSTR)(in_EAX + 0x644));
      goto LAB_005db3fa;
    }
  }
  iVar6 = (**(code **)(**(int **)(in_EAX + 0x56c) + 0x18))();
  if (iVar6 == 0) {
    uStack_264._0_4_ = (undefined4 *)(in_EAX + 0x57c);
    puVar1 = (uint *)(in_EAX + 0x578);
    iVar6 = FUN_005d91b0(*(undefined4 *)(in_EAX + 0x570),&DAT_0085f544,puVar1,
                         (undefined4 *)uStack_264);
    if (iVar6 == 0) {
      if (param_4 != 0) {
        if (param_2 != (uint *)0x0) {
          *param_2 = *puVar1;
        }
        if (param_3 != (undefined4 *)0x0) {
          *param_3 = *(undefined4 *)uStack_264;
        }
        return 0;
      }
      puVar2 = (uint *)(in_EAX + 0x584);
      iVar6 = FUN_005d91b0(*(undefined4 *)(in_EAX + 0x570),&DAT_0085f554,in_EAX + 0x580,puVar2);
      if (iVar6 == 0) {
        iVar6 = FUN_005d91b0(*(undefined4 *)(in_EAX + 0x570),&DAT_0085f564,in_EAX + 0x588,
                             in_EAX + 0x58c);
        if (iVar6 == 0) {
          iVar6 = (**(code **)(**(int **)(in_EAX + 0x56c) + 0x30))
                            (*(int **)(in_EAX + 0x56c),0xffffffff,&DAT_0085f424,in_EAX + 0x5a0);
          if (iVar6 == 0) {
            iVar6 = in_EAX + 0x5a8;
            *(undefined4 *)(in_EAX + 0xa8) = *(undefined4 *)(in_EAX + 0x5a8);
            uStack_264._0_4_ = *(undefined4 **)(in_EAX + 0x580);
            *(undefined4 *)(in_EAX + 0xac) = *(undefined4 *)(in_EAX + 0x5ac);
            puVar13 = auStack_24c;
            puVar11 = &uStack_264;
            uStack_264._4_4_ = 0;
            FUN_0056d6c0();
            uStack_264 = (ulonglong)*puVar2 * 10000000;
            FUN_0056d730(auStack_24c,&uStack_264,auStack_258,iVar6,puVar11,puVar13);
            puVar3 = (undefined4 *)(in_EAX + 0x574);
            *(uint *)(in_EAX + 0x5b8) = auStack_258[0];
            (*DAT_00aba210)(puVar3);
            (**(code **)(*(int *)*puVar3 + 0x60))((int *)*puVar3,&DAT_0085f434,&DAT_0085f3a4);
            (**(code **)(*(int *)*puVar3 + 0x60))((int *)*puVar3,&DAT_0085f444,&DAT_0085f784);
            (**(code **)(*(int *)*puVar3 + 0x54))((int *)*puVar3,&DAT_0085f534,*puVar1);
            FUN_005d91f0(*puVar3,&DAT_0085f554,*(undefined4 *)(in_EAX + 0x580),*puVar2);
            FUN_005d91f0(*puVar3,&DAT_0085f544,*puVar1,*(undefined4 *)(in_EAX + 0x57c));
            (**(code **)(*(int *)*puVar3 + 0x54))((int *)*puVar3,&DAT_0085f454,1);
            FUN_005d91f0(*puVar3,&DAT_0085f564,*(undefined4 *)(in_EAX + 0x588),
                         *(undefined4 *)(in_EAX + 0x58c));
            iVar6 = (**(code **)(**(int **)(in_EAX + 0x56c) + 0x1c))
                              (*(int **)(in_EAX + 0x56c),0xfffffffc,0,*puVar3);
            if (iVar6 == 0) {
              if (*(int *)(in_EAX + 0x580) == 0) {
                *(undefined4 *)(in_EAX + 0x638) = 0x28b0a;
                *(undefined4 *)(in_EAX + 0x63c) = 0;
              }
              else {
                uVar10 = __alldiv((ulonglong)*puVar2 * 10000000,*(int *)(in_EAX + 0x580),0);
                *(undefined8 *)(in_EAX + 0x638) = uVar10;
              }
              *(undefined8 *)(in_EAX + 0x5f0) = 0x3ff0000000000000;
              *(uint *)(in_EAX + 0x504) = *puVar1;
              *(uint *)(in_EAX + 0x50c) = *puVar1 * 4 + 0xf & 0xfffffff0;
              *(undefined4 *)(in_EAX + 0xd8) = 0;
              *(undefined4 *)(in_EAX + 0x5dc) = 0;
              *(undefined4 *)(in_EAX + 0x508) = *(undefined4 *)(in_EAX + 0x57c);
              iVar6 = FUN_0056e030();
              *(int *)(in_EAX + 0x5bc) = iVar6;
              if (iVar6 != 0) {
                iVar9 = *(int *)(in_EAX + 0x508) * *(int *)(in_EAX + 0x50c);
                uVar12 = 0;
                FUN_0056d380();
                *(undefined4 *)(in_EAX + 0x510) = *(undefined4 *)(in_EAX + 0x5bc);
                *(undefined4 *)(in_EAX + 0x51c) = 1;
                FUN_005444a0(in_EAX + 0xdc,iVar6,uVar12,iVar9);
                *(uint *)(in_EAX + 0x600) = *puVar1;
                uVar8 = *puVar1 + 0xf & 0xfffffff0;
                *(uint *)(in_EAX + 0x608) = uVar8;
                *(int *)(in_EAX + 0x524) = in_EAX + 0xdc;
                *(int *)(in_EAX + 0x604) = *(int *)(in_EAX + 0x57c);
                iVar6 = FUN_0056e030(uVar8 * *(int *)(in_EAX + 0x57c),
                                     "..\\..\\..\\..\\Source\\Library\\Main\\Windows\\DxMovieWin.cpp"
                                     ,0x1a4);
                *(int *)(in_EAX + 0x5f8) = iVar6;
                if (iVar6 != 0) {
                  *(uint *)(in_EAX + 0x60c) = *puVar1 >> 1;
                  *(uint *)(in_EAX + 0x610) = *(uint *)(in_EAX + 0x57c) >> 1;
                  *(uint *)(in_EAX + 0x614) = *puVar1 + 0xf & 0xfffffff0;
                  iVar6 = FUN_0056e030();
                  *(int *)(in_EAX + 0x5fc) = iVar6;
                  if (iVar6 != 0) {
                    if (param_2 != (uint *)0x0) {
                      *param_2 = *puVar1;
                    }
                    if (param_3 != (undefined4 *)0x0) {
                      *param_3 = *(undefined4 *)(in_EAX + 0x57c);
                    }
                    FUN_00550fd0(auStack_23c);
                    auStack_23c[0] = 1;
                    uStack_204 = 1;
                    uStack_20c = 0xffffffbf;
                    uStack_234 = 3;
                    uVar12 = FUN_005633a0(auStack_23c,in_EAX + 0x644,1,0xffffffff,0,param_5);
                    *(undefined4 *)(in_EAX + 0x5e0) = uVar12;
                    uVar12 = FUN_0055d360(uVar12);
                    *(undefined4 *)(in_EAX + 0x5e8) = uVar12;
                    uVar12 = FUN_005611b0(*(undefined4 *)(in_EAX + 0x5e0));
                    *(undefined4 *)(in_EAX + 0x5e4) = uVar12;
                    *(undefined4 *)(in_EAX + 0x5d8) = 0;
                    *(undefined4 *)(in_EAX + 0x618) = 0;
                    *(undefined4 *)(in_EAX + 0x620) = 0;
                    if (DAT_00a37dc8 == 0) {
                      FUN_005d9250();
                      return 0;
                    }
                    FUN_005d9250();
                    return 0;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
LAB_005db3fa:
  piVar5 = *(int **)(in_EAX + 0x56c);
  if (piVar5 != (int *)0x0) {
    (**(code **)(*piVar5 + 8))(piVar5);
    *(undefined4 *)(in_EAX + 0x56c) = 0;
  }
  piVar5 = *(int **)(in_EAX + 0x570);
  if (piVar5 != (int *)0x0) {
    (**(code **)(*piVar5 + 8))(piVar5);
    *(undefined4 *)(in_EAX + 0x570) = 0;
  }
  piVar5 = *(int **)(in_EAX + 0x574);
  if (piVar5 != (int *)0x0) {
    (**(code **)(*piVar5 + 8))(piVar5);
    *(undefined4 *)(in_EAX + 0x574) = 0;
  }
  if (*(int *)(in_EAX + 0x5bc) != 0) {
    FUN_0056e1d0(*(int *)(in_EAX + 0x5bc));
    *(undefined4 *)(in_EAX + 0x5bc) = 0;
  }
  if (*(int *)(in_EAX + 0x5f8) != 0) {
    FUN_0056e1d0(*(int *)(in_EAX + 0x5f8));
    *(undefined4 *)(in_EAX + 0x5f8) = 0;
  }
  if (*(int *)(in_EAX + 0x5fc) != 0) {
    FUN_0056e1d0(*(int *)(in_EAX + 0x5fc));
    *(undefined4 *)(in_EAX + 0x5fc) = 0;
  }
  return 0xffffffff;
}

