
int FUN_005d9dc0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5,
                undefined4 param_6,undefined4 param_7)

{
  undefined4 *puVar1;
  short sVar2;
  int *piVar3;
  int iVar4;
  short *psVar5;
  LPCVOID lpBuffer;
  DWORD nNumberOfBytesToWrite;
  undefined4 *unaff_retaddr;
  wchar_t *pwVar6;
  int local_214;
  uint uStack_210;
  uint uStack_20c;
  HANDLE pvStack_208;
  DWORD DStack_204;
  undefined1 local_200 [508];
  undefined4 *puStack_4;
  
  *(undefined4 *)(param_1 + 0x510) = 0;
  *(undefined4 *)(param_1 + 0xd4) = 0;
  *(undefined4 *)(param_1 + 0x530) = 0;
  *(undefined4 *)(param_1 + 0x534) = 0;
  *(undefined4 *)(param_1 + 0x538) = 0;
  *(undefined4 *)(param_1 + 0x53c) = 0;
  *(undefined4 *)(param_1 + 0xd0) = 0;
  FUN_0056d380(param_1 + 0x540,0,0x10);
  FUN_0056d380(param_1 + 0x550,0,0x10);
  if ((param_5 == 1) || (param_5 == 2)) {
    FUN_005167e0();
  }
  puVar1 = (undefined4 *)(param_1 + 0x624);
  iVar4 = FUN_0056cda0(&DAT_0085e814,0,3,&DAT_0085ea44,puVar1,param_7);
  if (iVar4 < 0) {
    pwVar6 = L"CoCreateInstance Error : CLSID_FilterGraph\n";
  }
  else {
    iVar4 = FUN_006046b0(0,&local_214);
    *(int *)(param_1 + 0x634) = iVar4;
    if (iVar4 == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = iVar4 + 0xc;
    }
    iVar4 = (**(code **)(*(int *)*puVar1 + 0xc))((int *)*puVar1,iVar4,L"MovieRenderer");
    if (iVar4 < 0) {
      FUN_0056cf70(&uStack_20c,0x200,L"Could not add renderer filter to graph!\n");
      return iVar4;
    }
    iVar4 = (*(code *)**(undefined4 **)*puVar1)((undefined4 *)*puVar1,&DAT_0085e994,param_1 + 0x630)
    ;
    if (-1 < iVar4) {
      iVar4 = (*(code *)**(undefined4 **)*puVar1)
                        ((undefined4 *)*puVar1,&DAT_0085e9d4,param_1 + 0x628);
      if (iVar4 < 0) {
        FUN_0056cf70(local_200,0x200,L"QueryInterface Error : IID_IMediaControl\n");
      }
      else {
        iVar4 = (*(code *)**(undefined4 **)*puVar1)
                          ((undefined4 *)*puVar1,&DAT_0085e9a4,param_1 + 0x62c);
        if (iVar4 < 0) {
          FUN_0056cf70(local_200,0x200,L"QueryInterface Error : IID_IMediaSeeking\n");
        }
        else {
          psVar5 = (short *)(param_1 + 0x644);
          FUN_0056cf70(psVar5,0xc00,param_2);
          sVar2 = *psVar5;
          while (sVar2 != 0) {
            if (*psVar5 == 0x2f) {
              *psVar5 = 0x5c;
            }
            psVar5 = psVar5 + 1;
            sVar2 = *psVar5;
          }
          local_214 = (**(code **)(**(int **)(param_1 + 0x624) + 0x34))
                                (*(int **)(param_1 + 0x624),param_1 + 0x644,0);
          if (-1 < local_214) {
LAB_005da1d9:
            piVar3 = (int *)(param_1 + 0x638);
            (**(code **)(**(int **)(param_1 + 0x62c) + 0x28))(*(int **)(param_1 + 0x62c),piVar3);
            if (*piVar3 == 0 && *(int *)(param_1 + 0x63c) == 0) {
              *piVar3 = 0x28b0a;
              *(undefined4 *)(param_1 + 0x63c) = 0;
            }
            (**(code **)(**(int **)(param_1 + 0x62c) + 0x2c))
                      (*(int **)(param_1 + 0x62c),param_1 + 0xa8);
            iVar4 = *(int *)(param_1 + 0x634);
            *(undefined4 *)(param_1 + 0x504) = *(undefined4 *)(iVar4 + 400);
            *(undefined4 *)(param_1 + 0x508) = *(undefined4 *)(iVar4 + 0x194);
            *(undefined4 *)(param_1 + 0x50c) = *(undefined4 *)(iVar4 + 0x198);
            *(undefined4 *)(param_1 + 0x510) = *(undefined4 *)(iVar4 + 0x17c);
            *(undefined4 *)(param_1 + 0x51c) = 1;
            if (*(int *)(iVar4 + 0x178) == 0) {
              FUN_00544560(param_1 + 0xdc);
            }
            else if ((*(int *)(iVar4 + 0x178) == 1) && (*(int *)(param_1 + 0xc0) != 0)) {
              FUN_00544500(param_1 + 0xdc);
            }
            else {
              FUN_005444a0(param_1 + 0xdc);
            }
            *(int *)(param_1 + 0x524) = param_1 + 0xdc;
            if (puStack_4 != (undefined4 *)0x0) {
              *puStack_4 = *(undefined4 *)(*(int *)(param_1 + 0x634) + 400);
            }
            if (unaff_retaddr != (undefined4 *)0x0) {
              *unaff_retaddr = *(undefined4 *)(*(int *)(param_1 + 0x634) + 0x194);
            }
            return 0;
          }
          FUN_0056cf70(local_200,0x200,L"RenderFile faired!\n");
          FUN_0056cf70(local_200,0x200,L"Movie File Open Error : ");
          FUN_0056d040(local_200,0x200,param_2);
          FUN_0056d040(local_200,0x200,&DAT_007d4b08);
          if ((*(int *)(param_1 + 0x640) != 1) &&
             (iVar4 = thunk_FUN_00572540(param_2,0,1,0), iVar4 != 0)) {
            FUN_0052c610(iVar4,0,0,2);
            uStack_210 = thunk_FUN_00571dd0(iVar4);
            FUN_0052c610(iVar4,0,0,0);
            lpBuffer = (LPCVOID)FUN_0056e030(0x100000,
                                             "..\\..\\..\\..\\Source\\Library\\Main\\Windows\\DxMovieWin.cpp"
                                             ,0x42c);
            if (lpBuffer == (LPCVOID)0x0) {
              thunk_FUN_00571d20(iVar4);
            }
            else {
              pvStack_208 = (HANDLE)FUN_00594cb0(param_1 + 0x644,0xc00);
              if (pvStack_208 == (HANDLE)0x0) {
                thunk_FUN_00571d20(iVar4);
                FUN_0056e1d0(lpBuffer);
              }
              else {
                *(undefined4 *)(param_1 + 0x640) = 1;
                uStack_20c = 0;
                if (uStack_210 != 0) {
                  do {
                    nNumberOfBytesToWrite = uStack_20c - uStack_210;
                    if (0x100000 < nNumberOfBytesToWrite) {
                      nNumberOfBytesToWrite = 0x100000;
                    }
                    thunk_FUN_00571e60(lpBuffer,nNumberOfBytesToWrite,1,iVar4);
                    WriteFile(pvStack_208,lpBuffer,nNumberOfBytesToWrite,&DStack_204,
                              (LPOVERLAPPED)0x0);
                  } while ((nNumberOfBytesToWrite == DStack_204) &&
                          (uStack_20c = uStack_20c + nNumberOfBytesToWrite, uStack_20c < uStack_210)
                          );
                }
                thunk_FUN_00571d20(iVar4);
                CloseHandle(pvStack_208);
                FUN_0056e1d0(lpBuffer);
                local_214 = (**(code **)(**(int **)(param_1 + 0x624) + 0x34))
                                      (*(int **)(param_1 + 0x624),(LPCWSTR)(param_1 + 0x644),0);
                if (-1 < local_214) goto LAB_005da1d9;
                DeleteFileW((LPCWSTR)(param_1 + 0x644));
              }
            }
          }
        }
      }
      goto LAB_005da167;
    }
    pwVar6 = L"QueryInterface Error : IID_IBasicAudio\n";
  }
  FUN_0056cf70(local_200,0x200,pwVar6);
LAB_005da167:
  piVar3 = *(int **)(param_1 + 0x624);
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 8))(piVar3);
    *(int *)(param_1 + 0x624) = 0;
  }
  piVar3 = *(int **)(param_1 + 0x628);
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 8))(piVar3);
    *(undefined4 *)(param_1 + 0x628) = 0;
  }
  piVar3 = *(int **)(param_1 + 0x62c);
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 8))(piVar3);
    *(undefined4 *)(param_1 + 0x62c) = 0;
  }
  piVar3 = *(int **)(param_1 + 0x630);
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 8))(piVar3);
    *(undefined4 *)(param_1 + 0x630) = 0;
  }
  iVar4 = FUN_0056bb00(local_200);
  return iVar4;
}

