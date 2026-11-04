
int FUN_005764b0(int *param_1,uint param_2,int param_3,int param_4,uint param_5,int param_6)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint local_c;
  uint local_8;
  int local_4;
  
  iVar1 = param_6;
  if (DAT_00b239c0 == 0) {
    FUN_005728b0();
  }
  if (param_3 == param_6) {
    iVar1 = FUN_00572ac0(param_3);
    if (iVar1 == 1) {
      uVar6 = 0;
      if (param_5 == 0) {
        return 0;
      }
      if (param_5 != 1) {
        iVar1 = param_4 - (int)param_1;
        do {
          if (((-1 < (int)param_2) && (param_2 <= uVar6)) || ((char)*param_1 == '\0')) break;
          *(char *)((int)param_1 + iVar1) = (char)*param_1;
          uVar6 = uVar6 + 1;
          param_1 = (int *)((int)param_1 + 1);
        } while (uVar6 < param_5 - 1);
      }
      *(undefined1 *)(uVar6 + param_4) = 0;
      return uVar6 + 1;
    }
    if (iVar1 == 2) {
      if (1 < param_5) {
        uVar6 = 0;
        if (param_5 != 2) {
          uVar4 = 0;
          iVar1 = param_4 - (int)param_1;
          do {
            if (((-1 < (int)param_2) && (param_2 <= uVar6)) || ((short)*param_1 == 0)) break;
            *(short *)((int)param_1 + iVar1) = (short)*param_1;
            uVar4 = uVar4 + 2;
            uVar6 = uVar6 + 1;
            param_1 = (int *)((int)param_1 + 2);
          } while (uVar4 < param_5 - 2);
        }
        *(undefined2 *)(param_4 + uVar6 * 2) = 0;
        return uVar6 * 2 + 2;
      }
    }
    else {
      if (iVar1 != 4) {
        return -1;
      }
      if (3 < param_5) {
        uVar6 = 0;
        if (param_5 != 4) {
          uVar4 = 0;
          iVar1 = param_4 - (int)param_1;
          do {
            if (((-1 < (int)param_2) && (param_2 <= uVar6)) || (*param_1 == 0)) break;
            *(int *)(iVar1 + (int)param_1) = *param_1;
            uVar4 = uVar4 + 4;
            uVar6 = uVar6 + 1;
            param_1 = param_1 + 1;
          } while (uVar4 < param_5 - 4);
        }
        *(undefined4 *)(param_4 + uVar6 * 4) = 0;
        return uVar6 * 4 + 4;
      }
    }
  }
  else {
    if (param_3 < 0x7fff) {
      if (param_3 == 0x7ffe) {
        if (param_6 < 0x7ffe) {
          if (param_6 == 0x7ffd) {
            iVar1 = FUN_005760d0(param_1,param_2,param_4,param_5);
            return iVar1;
          }
          if (param_6 == 0x3a4) {
            iVar1 = FUN_005761c0(param_1,param_2,param_4,param_5);
            return iVar1;
          }
          if (param_6 == 0x4b0) {
            iVar1 = FUN_00574d00(param_1,param_2,param_4,param_5);
            return iVar1;
          }
          if (param_6 == 0x4b1) {
            iVar1 = FUN_00574e00(param_1,param_2,param_4,param_5);
            return iVar1;
          }
        }
        else {
          if (param_6 == 0x7fff) {
            iVar1 = FUN_00575000(param_1,param_2,param_4,param_5);
            return iVar1;
          }
          if (param_6 == 0xfde9) {
            iVar1 = FUN_00574f00(param_1,param_2,param_4,param_5);
            return iVar1;
          }
        }
      }
      else if (param_3 == 0x3a4) {
        if (param_6 < 0x7fff) {
          if (param_6 == 0x7ffe) {
            iVar1 = FUN_00575910(param_1,param_2,param_4,param_5);
            return iVar1;
          }
          if (param_6 == 0x4b0) {
            iVar1 = FUN_00575620(param_1,param_2,param_4,param_5);
            return iVar1;
          }
          if (param_6 == 0x4b1) {
            iVar1 = FUN_00575720(param_1,param_2,param_4,param_5);
            return iVar1;
          }
          if (param_6 == 0x7ffd) {
            iVar1 = FUN_00575520(param_1,param_2,param_4,param_5);
            return iVar1;
          }
        }
        else {
          if (param_6 == 0x7fff) {
            iVar1 = FUN_00575a20(param_1,param_2,param_4,param_5);
            return iVar1;
          }
          if (param_6 == 0xfde9) {
            iVar1 = FUN_00575820(param_1,param_2,param_4,param_5);
            return iVar1;
          }
        }
      }
      else if (param_3 == 0x4b0) {
        if (param_6 < 0x7fff) {
          if (param_6 == 0x7ffe) {
            iVar1 = FUN_005742b0(param_1,param_2,param_4,param_5);
            return iVar1;
          }
          if (param_6 == 0x3a4) {
            iVar1 = FUN_00575c20(param_1,param_2,param_4,param_5);
            return iVar1;
          }
          if (param_6 == 0x4b1) {
            iVar1 = FUN_005740d0(param_1,param_2,param_4,param_5);
            return iVar1;
          }
          if (param_6 == 0x7ffd) {
            iVar1 = FUN_00575b30(param_1,param_2,param_4,param_5);
            return iVar1;
          }
        }
        else {
          if (param_6 == 0x7fff) {
            iVar1 = FUN_005743c0(param_1,param_2,param_4,param_5);
            return iVar1;
          }
          if (param_6 == 0xfde9) {
            iVar1 = FUN_005741c0(param_1,param_2,param_4,param_5);
            return iVar1;
          }
        }
      }
      else if (param_3 == 0x4b1) {
        if (param_6 < 0x7fff) {
          if (param_6 == 0x7ffe) {
            iVar1 = FUN_005746c0(param_1,param_2,param_4,param_5);
            return iVar1;
          }
          if (param_6 == 0x3a4) {
            iVar1 = FUN_00575e00(param_1,param_2,param_4,param_5);
            return iVar1;
          }
          if (param_6 == 0x4b0) {
            iVar1 = FUN_005744e0(param_1,param_2,param_4,param_5);
            return iVar1;
          }
          if (param_6 == 0x7ffd) {
            iVar1 = FUN_00575d10(param_1,param_2,param_4,param_5);
            return iVar1;
          }
        }
        else {
          if (param_6 == 0x7fff) {
            iVar1 = FUN_005747d0(param_1,param_2,param_4,param_5);
            return iVar1;
          }
          if (param_6 == 0xfde9) {
            iVar1 = FUN_005745d0(param_1,param_2,param_4,param_5);
            return iVar1;
          }
        }
      }
    }
    else if (param_3 == 0x7fff) {
      if (param_6 < 0x7ffe) {
        if (param_6 == 0x7ffd) {
          iVar1 = FUN_005762c0(param_1,param_2,param_4,param_5);
          return iVar1;
        }
        if (param_6 == 0x3a4) {
          iVar1 = FUN_005763b0(param_1,param_2,param_4,param_5);
          return iVar1;
        }
        if (param_6 == 0x4b0) {
          iVar1 = FUN_00575110(param_1,param_2,param_4,param_5);
          return iVar1;
        }
        if (param_6 == 0x4b1) {
          iVar1 = FUN_00575210(param_1,param_2,param_4,param_5);
          return iVar1;
        }
      }
      else {
        if (param_6 == 0x7ffe) {
          iVar1 = FUN_00575410(param_1,param_2,param_4,param_5);
          return iVar1;
        }
        if (param_6 == 0xfde9) {
          iVar1 = FUN_00575310(param_1,param_2,param_4,param_5);
          return iVar1;
        }
      }
    }
    else if (param_3 == 0xfde9) {
      if (param_6 < 0x7ffe) {
        if (param_6 == 0x7ffd) {
          iVar1 = FUN_00575ef0(param_1,param_2,param_4,param_5);
          return iVar1;
        }
        if (param_6 == 0x3a4) {
          iVar1 = FUN_00575fe0(param_1,param_2,param_4,param_5);
          return iVar1;
        }
        if (param_6 == 0x4b0) {
          iVar1 = FUN_005748f0(param_1,param_2,param_4,param_5);
          return iVar1;
        }
        if (param_6 == 0x4b1) {
          iVar1 = FUN_005749e0(param_1,param_2,param_4,param_5);
          return iVar1;
        }
      }
      else {
        if (param_6 == 0x7ffe) {
          iVar1 = FUN_00574ad0(param_1,param_2,param_4,param_5);
          return iVar1;
        }
        if (param_6 == 0x7fff) {
          iVar1 = FUN_00574be0(param_1,param_2,param_4,param_5);
          return iVar1;
        }
      }
    }
    iVar5 = 0;
    param_6 = param_4;
    local_8 = FUN_00573310(0,iVar1,param_4,param_5);
    if (local_8 != 0) {
      local_c = 0;
      while ((((int)param_2 < 0 || (local_c < param_2)) &&
             (iVar2 = FUN_00572c90(param_1,param_3,&local_4,&local_c), iVar2 != 0))) {
        param_1 = (int *)((int)param_1 + local_4);
        uVar3 = FUN_005736c0(iVar2,param_3,iVar1);
        iVar2 = FUN_00573310(uVar3,iVar1,param_6,param_5 - iVar5);
        if ((iVar2 == 0) || (param_5 - iVar5 < iVar2 + local_8)) break;
        if (param_6 != 0) {
          param_6 = param_6 + iVar2;
        }
        iVar5 = iVar5 + iVar2;
        if (param_5 - iVar5 <= local_8) break;
      }
      iVar1 = FUN_00573310(0,iVar1,param_6,param_5 - iVar5);
      return iVar1 + iVar5;
    }
  }
  return 0;
}

