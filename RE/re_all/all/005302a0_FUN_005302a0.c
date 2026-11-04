
undefined4 __thiscall
FUN_005302a0(char *param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5)

{
  char cVar1;
  uint in_EAX;
  int iVar2;
  int iVar3;
  uint *puVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  
  iVar7 = 0;
  if ((((DAT_00cc5c60 != 0) && (-1 < (int)in_EAX)) && ((in_EAX & 0x7c000000) == DAT_00cc5c88)) &&
     ((int)(in_EAX & 0xffff) < DAT_00cc5c90)) {
    iVar7 = *(int *)(DAT_00cc5c64 + (in_EAX & 0xffff) * 4);
  }
  if (param_4 < 0) {
    param_4 = 0;
  }
  if (((*param_1 == 'F') && (param_1[1] == 'N')) && ((param_1[2] == 'T' && (param_1[3] == 'F')))) {
    *(undefined4 *)(iVar7 + 0x38) = 1;
    iVar2 = FUN_00570180(param_1 + 0x18,0);
    iVar3 = FUN_0056e030(*(int *)(param_1 + 0xc) + 0x40000 + *(int *)(param_1 + 0x14) * 4 +
                         iVar2 + 0x18 + param_3,"..\\..\\..\\..\\Source\\Library\\Main\\DxFont.cpp",
                         0x1928);
    *(int *)(iVar7 + 0x3c) = iVar3;
    if (iVar3 != 0) {
      iVar6 = iVar2 + 0x18 + iVar3 + param_3;
      *(int *)(iVar7 + 0x44) = iVar3 + param_3;
      iVar2 = iVar6 + 0x40000;
      *(int *)(iVar7 + 0x58) = iVar2;
      *(int *)(iVar7 + 0x54) = iVar6;
      *(int *)(iVar7 + 0x5c) = iVar2 + *(int *)(param_1 + 0x14) * 4;
      FUN_0056d420(iVar3,param_1,param_3);
      *(int *)(iVar7 + 0x40) = param_3;
      FUN_00570180(*(int *)(iVar7 + 0x3c) + 0x18,*(int *)(iVar7 + 0x44) + 0x18);
      FUN_0056d420(*(undefined4 *)(iVar7 + 0x44),*(undefined4 *)(iVar7 + 0x3c),0x18);
      iVar2 = *(int *)(iVar7 + 0x44);
      *(int *)(iVar7 + 0x48) = iVar2 + 0x170;
      *(int *)(iVar7 + 0x4c) = *(int *)(iVar2 + 8) + *(int *)(iVar7 + 0x3c);
      cVar1 = *(char *)(iVar2 + 300);
      if (cVar1 == '\0') {
        *(undefined4 *)(iVar7 + 0x50) = 0;
        *(uint *)(iVar7 + 0x93184) = (uint)(0 < param_4);
      }
      else if (cVar1 == '\x01') {
        *(undefined4 *)(iVar7 + 0x50) = 4;
        *(uint *)(iVar7 + 0x93184) = (0 < param_4) + 0x12;
      }
      else if (cVar1 == '\x02') {
        *(undefined4 *)(iVar7 + 0x50) = 8;
        *(uint *)(iVar7 + 0x93184) = (0 < param_4) + 0x22;
      }
      FUN_0056d380(*(undefined4 *)(iVar7 + 0x54),0,0x40000);
      puVar4 = *(uint **)(iVar7 + 0x48);
      uVar5 = 0;
      if (*(int *)(*(int *)(iVar7 + 0x44) + 0x10) != 0) {
        iVar2 = 0;
        do {
          if (*puVar4 < 0x10000) {
            *(uint **)(*(int *)(iVar7 + 0x54) + *puVar4 * 4) = puVar4;
          }
          else {
            *(uint **)(iVar2 + *(int *)(iVar7 + 0x58)) = puVar4;
            iVar2 = iVar2 + 4;
          }
          uVar5 = uVar5 + 1;
          puVar4 = puVar4 + 8;
        } while (uVar5 < *(uint *)(*(int *)(iVar7 + 0x44) + 0x10));
      }
      FUN_0056d420(iVar7 + 0x93160,*(int *)(iVar7 + 0x44) + 0x118,0x14);
      *(int *)(iVar7 + 0x93188) = param_4;
      *(undefined4 *)(iVar7 + 0x93178) = 0;
      *(undefined4 *)(iVar7 + 0x9317c) = 0;
      *(undefined4 *)(iVar7 + 0x93180) = 0;
      *(undefined4 *)(iVar7 + 0x93174) = 0xffffffff;
      if (DAT_00aba250 == 0) {
        FUN_0057a980();
      }
      FUN_005764b0(*(int *)(iVar7 + 0x44) + 0x18,0xffffffff,0x4b0,iVar7 + 0x92f60,0x200,DAT_00aba250
                  );
      if (DAT_00aba24c == 0) {
        FUN_0057a980();
      }
      iVar2 = DAT_00aba24c;
      if (DAT_00aba250 == 0) {
        FUN_0057a980();
      }
      FUN_005764b0(iVar7 + 0x92f60,0xffffffff,DAT_00aba250,iVar7 + 0x92e60,0x100,iVar2);
      *(undefined4 *)(iVar7 + 0x34) = 0;
      iVar2 = FUN_00595780(param_2,iVar7,0);
      if ((iVar2 == 0) && (iVar2 = FUN_0052f260(param_2,iVar7,param_5), -1 < iVar2)) {
        return 0;
      }
    }
  }
  FUN_00595f60(iVar7);
  if (*(int *)(iVar7 + 0x3c) != 0) {
    FUN_0056e1d0(*(int *)(iVar7 + 0x3c));
    *(undefined4 *)(iVar7 + 0x3c) = 0;
  }
  return 0xffffffff;
}

