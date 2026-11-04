
undefined4 FUN_00530d80(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *puVar7;
  uint uVar8;
  uint local_24;
  uint local_20;
  uint local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if (0 < DAT_00a4bca8) {
    iVar2 = FUN_0052eda0(DAT_00a4bca8);
    if ((DAT_00a4bec4 & 1) == 0) {
      local_24 = 0xffffffff;
    }
    else {
      local_24 = DAT_00a4bed8;
    }
    local_20 = DAT_00a4bee0;
    if (DAT_00a4bec4 == 0xffffffff) {
      uVar5 = -(uint)(DAT_00a4b76c != 0) & 2;
    }
    else {
      uVar5 = DAT_00a4bec4;
      if (DAT_00a4b76c != 0) {
        uVar5 = ((DAT_00a4bec4 & 1) != 0) + 2;
      }
    }
    if (1 < (int)local_24) {
      uVar5 = uVar5 | 1;
    }
    uVar8 = DAT_00a4beb4;
    if (DAT_00a4beb4 == 0xffffffff) {
      uVar8 = 0x10;
    }
    uVar6 = DAT_00a4bebc;
    if (DAT_00a4bebc == 0xffffffff) {
      uVar6 = 6;
    }
    if (local_24 == 0xffffffff) {
      local_24 = 1;
    }
    if (DAT_00a4baa0 == 1) {
      if (0 < DAT_00a4baa8) {
        return 0;
      }
    }
    else if (((DAT_00a4baa0 == 0) &&
             ((((DAT_00a4bcb0 == 0 ||
                (iVar3 = FUN_0056d130(&DAT_00a4bcb0,iVar2 + 0x92f60), iVar3 == 0)) &&
               (uVar5 == *(uint *)(iVar2 + 0x93184))) &&
              ((uVar8 == *(ushort *)(iVar2 + 0x93162) && (uVar6 == *(ushort *)(iVar2 + 0x93160))))))
             ) && ((DAT_00a4bed0 == 0 &&
                   ((((uVar5 & 1) == 0 || (local_24 == *(uint *)(iVar2 + 0x93188))) &&
                    (local_20 == *(byte *)(iVar2 + 0x93168))))))) {
      return 0;
    }
    FUN_00580b80(DAT_00a4bca8);
  }
  uVar5 = DAT_00a4bee0;
  uVar4 = DAT_00a4becc;
  local_c = DAT_00a4b770;
  local_8 = DAT_00a4b774;
  local_10 = DAT_00a4b768;
  local_14 = DAT_00a4b764;
  local_4 = DAT_00a4b778;
  if ((DAT_00a4bec4 & 1) == 0) {
    local_20 = 0xffffffff;
  }
  else {
    local_20 = DAT_00a4bed8;
  }
  local_24 = DAT_00a4bebc;
  local_1c = DAT_00a4beb4;
  if ((DAT_00a21078 == 0) && (DAT_00a238d0 == 0)) {
    FUN_0050e770();
  }
  iVar2 = FUN_005809a0(8,0,0xffffffff);
  if (iVar2 != -1) {
    iVar3 = FUN_0052fdc0(&local_14,iVar2,&DAT_00a4bcb0,local_1c,local_24,uVar4,local_20,uVar5,0);
    if (-1 < iVar3) goto LAB_00530f92;
    FUN_00580b80(iVar2);
  }
  iVar2 = -1;
LAB_00530f92:
  DAT_00a4bed0 = 0;
  DAT_00a4bca8 = iVar2;
  if (iVar2 < 0) {
    local_24 = local_24 & 0xffff0000;
    DAT_00a4bca8 = FUN_00530960(&DAT_0084cba8,0x4f,0);
    if (DAT_00a4baa4 == 0) {
      if (DAT_00a4b758 == 0) {
        FUN_005702e0(&DAT_0084cbf8,&DAT_0084cbf8);
        DAT_00a4b758 = 1;
      }
      uVar4 = FUN_00570180(&DAT_0084cbf8,0,"..\\..\\..\\..\\Source\\Library\\Main\\DxFont.cpp",0x763
                          );
      DAT_00a4baa4 = FUN_0056e050(uVar4);
      if (DAT_00a4baa4 == 0) {
        return 0xffffffff;
      }
      FUN_00570180(&DAT_0084cbf8,DAT_00a4baa4);
    }
    if (DAT_00a4baa8 < 1) {
      FUN_0051d770(&local_18,&local_20,&local_1c);
      FUN_0051d740(0xff,0,0xff);
      uVar4 = FUN_00570180(&DAT_0084cbf8,0,0x80,0x10,8,8,0x10,&DAT_00a4baa8,1,0,0,0);
      FUN_0052a2d0(DAT_00a4baa4,uVar4);
      FUN_0051d740(local_18,local_20,local_1c);
      puVar7 = &DAT_00a4baa8;
      do {
        iVar2 = 0x10;
        do {
          FUN_00580830(*puVar7,puVar7);
          puVar7 = puVar7 + 1;
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
      } while ((int)puVar7 < 0xa4bca8);
    }
    local_20 = 0;
    puVar7 = &DAT_00a4baa8;
    do {
      iVar2 = 0;
      cVar1 = (char)local_20 * '\x10';
      do {
        local_24 = CONCAT31(local_24._1_3_,cVar1 + (char)iVar2);
        FUN_00530c20(DAT_00a4bca8,&local_24,*puVar7,0,0,8);
        iVar2 = iVar2 + 1;
        puVar7 = puVar7 + 1;
      } while (iVar2 < 0x10);
      local_20 = local_20 + 1;
    } while ((int)puVar7 < 0xa4bca8);
    DAT_00a4baa0 = 1;
  }
  else {
    DAT_00a4baa0 = 0;
    FUN_005309c0(DAT_00a4bee8,iVar2);
    if (DAT_00a4bef0 != 0) {
      FUN_00530a40(DAT_00a4bef4,DAT_00a4bca8);
    }
  }
  FUN_00580830(DAT_00a4bca8,&DAT_00a4bca8);
  return 0;
}

