
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004c40f0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  byte bVar8;
  int local_38;
  
  if (*(int *)(param_1 + 0x17c) != 0) {
    if (DAT_0084b264 == 0x28) {
      bVar8 = 2;
    }
    else {
      bVar8 = DAT_0084b264 == 0x20;
    }
    if ((*(int *)(param_1 + 0x16c) != 0) && (*(char *)(param_1 + 0x19c) != '\0')) {
      if (*(int *)(param_1 + 0x16c) == 0xff) {
        FUN_005160d0(0,0xff);
      }
      else {
        FUN_005160d0(1,*(undefined4 *)(param_1 + 0x16c));
      }
      iVar2 = ((bVar8 != 0) - 1) + *(int *)(param_1 + 0x180);
      iVar3 = *(int *)(param_1 + 0x180) + *(int *)(param_1 + 0x188) + (((bVar8 == 0) - 1 & 0xb) - 8)
              + ((bVar8 < 2) - 1 & 10);
      iVar1 = *(int *)(param_1 + 0x184);
      iVar7 = *(int *)(param_1 + 0x184) + *(int *)(param_1 + 0x18c) +
              (((bVar8 == 0) - 1 & 0xc) - 10);
      puVar4 = (undefined4 *)FUN_004ce990(1);
      FUN_0051f060(iVar2 * DAT_0084b248,iVar1 * DAT_0084b248,
                   (iVar2 + *(int *)(param_1 + 0x150)) * DAT_0084b248,
                   (iVar1 + *(int *)(param_1 + 0x158)) * DAT_0084b248,*puVar4);
      puVar4 = (undefined4 *)FUN_004ce990(3);
      FUN_0051f060((iVar3 - *(int *)(param_1 + 0x150)) * DAT_0084b248,iVar1 * DAT_0084b248,
                   iVar3 * DAT_0084b248,(iVar1 + *(int *)(param_1 + 0x158)) * DAT_0084b248,*puVar4);
      puVar4 = (undefined4 *)FUN_004ce990(2);
      FUN_0051f060((iVar2 + *(int *)(param_1 + 0x150)) * DAT_0084b248,iVar1 * DAT_0084b248,
                   (iVar3 - *(int *)(param_1 + 0x150)) * DAT_0084b248,
                   (iVar1 + *(int *)(param_1 + 0x158)) * DAT_0084b248,*puVar4);
      puVar4 = (undefined4 *)FUN_004ce990(4);
      FUN_0051f060(iVar2 * DAT_0084b248,(iVar1 + *(int *)(param_1 + 0x158)) * DAT_0084b248,
                   (iVar2 + *(int *)(param_1 + 0x150)) * DAT_0084b248,
                   (iVar7 - *(int *)(param_1 + 0x158)) * DAT_0084b248,*puVar4);
      puVar4 = (undefined4 *)FUN_004ce990(6);
      FUN_0051f060((iVar3 - *(int *)(param_1 + 0x150)) * DAT_0084b248,
                   (iVar1 + *(int *)(param_1 + 0x158)) * DAT_0084b248,iVar3 * DAT_0084b248,
                   (iVar7 - *(int *)(param_1 + 0x158)) * DAT_0084b248,*puVar4);
      puVar4 = (undefined4 *)FUN_004ce990(5);
      FUN_0051f060((iVar2 + *(int *)(param_1 + 0x150)) * DAT_0084b248,
                   (iVar1 + *(int *)(param_1 + 0x158)) * DAT_0084b248,
                   (iVar3 - *(int *)(param_1 + 0x150)) * DAT_0084b248,
                   (iVar7 - *(int *)(param_1 + 0x158)) * DAT_0084b248,*puVar4);
      puVar4 = (undefined4 *)FUN_004ce990(7);
      FUN_0051f060(iVar2 * DAT_0084b248,(iVar7 - *(int *)(param_1 + 0x158)) * DAT_0084b248,
                   (iVar2 + *(int *)(param_1 + 0x150)) * DAT_0084b248,iVar7 * DAT_0084b248,*puVar4);
      puVar4 = (undefined4 *)FUN_004ce990(9);
      FUN_0051f060((iVar3 - *(int *)(param_1 + 0x150)) * DAT_0084b248,
                   (iVar7 - *(int *)(param_1 + 0x158)) * DAT_0084b248,iVar3 * DAT_0084b248,
                   iVar7 * DAT_0084b248,*puVar4);
      puVar4 = (undefined4 *)FUN_004ce990(8);
      FUN_0051f060((iVar2 + *(int *)(param_1 + 0x150)) * DAT_0084b248,
                   (iVar7 - *(int *)(param_1 + 0x158)) * DAT_0084b248,
                   (iVar3 - *(int *)(param_1 + 0x150)) * DAT_0084b248,iVar7 * DAT_0084b248,*puVar4);
    }
    if ((((*(int *)(param_1 + 0x128) == 0) || (*(int *)(param_1 + 0x16c) == 0xff)) &&
        (-1 < *(int *)(param_1 + 0x178))) && (*(char *)(param_1 + 0x19d) != '\0')) {
      if (*(int *)(param_1 + 0x160) < *(int *)(param_1 + 0x164) / 5) {
        local_38 = *(int *)(param_1 + 0x160);
      }
      else {
        local_38 = *(int *)(param_1 + 0x164) / 5;
      }
      local_38 = local_38 * 9;
      FUN_005160d0(DAT_00a18b20 + 1,*(undefined4 *)(param_1 + 0x174));
      iVar1 = *(int *)(param_1 + 0x180) + (DAT_0084b264 << 1) / 10 + (DAT_0084b264 << 2) / 10 +
              (((bVar8 == 0) - 1 & 0xfffffffb) - 3);
      iVar6 = ((*(int *)(param_1 + 0x180) + *(int *)(param_1 + 0x188)) - (DAT_0084b264 << 2) / 10) +
              (((bVar8 == 0) - 1 & 0xc) - 9) + ((bVar8 < 2) - 1 & 10);
      piVar5 = (int *)FUN_004ce990();
      iVar2 = *(int *)(param_1 + 0x184) + *piVar5 + (DAT_0084b264 << 2) / 10 + (uint)(bVar8 == 0);
      piVar5 = (int *)FUN_004ce990();
      iVar3 = *(int *)(param_1 + 0x184);
      iVar7 = *piVar5;
      piVar5 = (int *)FUN_004ce990();
      iVar3 = iVar3 + iVar7 + *piVar5 + (DAT_0084b264 << 2) / 10 + 3;
      puVar4 = (undefined4 *)FUN_004ce990(local_38 + 1);
      FUN_0051f060(iVar1 * DAT_0084b248,iVar2 * DAT_0084b248,
                   (iVar1 + *(int *)(param_1 + 0x154)) * DAT_0084b248,
                   (iVar2 + *(int *)(param_1 + 0x15c)) * DAT_0084b248,*puVar4);
      puVar4 = (undefined4 *)FUN_004ce990(local_38 + 3);
      FUN_0051f060((iVar6 - *(int *)(param_1 + 0x154)) * DAT_0084b248,iVar2 * DAT_0084b248,
                   iVar6 * DAT_0084b248,(iVar2 + *(int *)(param_1 + 0x15c)) * DAT_0084b248,*puVar4);
      puVar4 = (undefined4 *)FUN_004ce990(local_38 + 2);
      FUN_0051f060((iVar1 + *(int *)(param_1 + 0x154)) * DAT_0084b248,iVar2 * DAT_0084b248,
                   (iVar6 - *(int *)(param_1 + 0x154)) * DAT_0084b248,
                   (iVar2 + *(int *)(param_1 + 0x15c)) * DAT_0084b248,*puVar4);
      puVar4 = (undefined4 *)FUN_004ce990(local_38 + 4);
      FUN_0051f060(iVar1 * DAT_0084b248,(iVar2 + *(int *)(param_1 + 0x15c)) * DAT_0084b248,
                   (iVar1 + *(int *)(param_1 + 0x154)) * DAT_0084b248,
                   (iVar3 - *(int *)(param_1 + 0x15c)) * DAT_0084b248,*puVar4);
      puVar4 = (undefined4 *)FUN_004ce990(local_38 + 6);
      FUN_0051f060((iVar6 - *(int *)(param_1 + 0x154)) * DAT_0084b248,
                   (iVar2 + *(int *)(param_1 + 0x15c)) * DAT_0084b248,iVar6 * DAT_0084b248,
                   (iVar3 - *(int *)(param_1 + 0x15c)) * DAT_0084b248,*puVar4);
      puVar4 = (undefined4 *)FUN_004ce990(local_38 + 5);
      FUN_0051f060((iVar1 + *(int *)(param_1 + 0x154)) * DAT_0084b248,
                   (iVar2 + *(int *)(param_1 + 0x15c)) * DAT_0084b248,
                   (iVar6 - *(int *)(param_1 + 0x154)) * DAT_0084b248,
                   (iVar3 - *(int *)(param_1 + 0x15c)) * DAT_0084b248,*puVar4);
      puVar4 = (undefined4 *)FUN_004ce990(local_38 + 7);
      FUN_0051f060(iVar1 * DAT_0084b248,(iVar3 - *(int *)(param_1 + 0x15c)) * DAT_0084b248,
                   (iVar1 + *(int *)(param_1 + 0x154)) * DAT_0084b248,iVar3 * DAT_0084b248,*puVar4);
      puVar4 = (undefined4 *)FUN_004ce990(local_38 + 9);
      FUN_0051f060((iVar6 - *(int *)(param_1 + 0x154)) * DAT_0084b248,
                   (iVar3 - *(int *)(param_1 + 0x15c)) * DAT_0084b248,iVar6 * DAT_0084b248,
                   iVar3 * DAT_0084b248,*puVar4);
      puVar4 = (undefined4 *)FUN_004ce990(local_38 + 8);
      FUN_0051f060((iVar1 + *(int *)(param_1 + 0x154)) * DAT_0084b248,
                   (iVar3 - *(int *)(param_1 + 0x15c)) * DAT_0084b248,
                   (iVar6 - *(int *)(param_1 + 0x154)) * DAT_0084b248,iVar3 * DAT_0084b248,*puVar4);
    }
    FUN_005160d0(0,0xff);
    if (*(int *)(param_1 + 0x194) < 1) {
      FUN_00494480(1,_DAT_00802e18,_DAT_00802e18,_DAT_007d0a60);
    }
  }
  return;
}

