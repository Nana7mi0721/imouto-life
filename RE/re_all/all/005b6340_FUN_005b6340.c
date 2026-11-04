
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005b6340(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  undefined4 *puVar6;
  uint *puVar7;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if (DAT_00f3a04c == 0) {
    return 0xffffffff;
  }
  FUN_005d3a70(0x1a,0);
  DAT_00e39a54 = 1;
  DAT_00e39a00 = 1;
  DAT_00e39a4c = 0;
  DAT_00e79678 = 0;
  FUN_0059b9c0(DAT_00e39a14,DAT_00e39a08,DAT_00e39a04);
  FUN_0059ba40(DAT_00e39a20);
  FUN_0059a970(DAT_00e79844);
  FUN_0059b3f0(DAT_00e7984c);
  FUN_0059a9e0(DAT_00e80638);
  FUN_0059b300(DAT_00e80500,0xffffffff);
  FUN_0059a970(DAT_00e79844);
  iVar3 = 0;
  do {
    FUN_0059ac30((&DAT_00e8065c)[iVar3],iVar3);
    FUN_0059adc0((&DAT_00e8069c)[iVar3],iVar3);
    FUN_0059af50((&DAT_00e806dc)[iVar3],iVar3);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 8);
  iVar3 = 0;
  puVar6 = &DAT_00e8075c;
  do {
    FUN_0059b110((&DAT_00e8071c)[iVar3],puVar6,iVar3);
    puVar6 = puVar6 + 0x10;
    iVar3 = iVar3 + 1;
  } while ((int)puVar6 < 0xe8095c);
  FUN_005a05e0(DAT_00e79874);
  FUN_005a0670(DAT_00e79878);
  FUN_005a0730(DAT_00e7987c);
  FUN_005a0800(_DAT_00e79880,_DAT_00e79884);
  FUN_005a0940(_DAT_00e79888);
  iVar3 = DAT_00e80b78;
  if ((DAT_00f3a04c != 0) && (DAT_00e39a54 != 0)) {
    FUN_005d3a70(7,DAT_00e80b78 == 1);
    DAT_00e39a00 = 1;
  }
  uVar1 = DAT_00e80b80;
  DAT_00e80b78 = iVar3;
  if ((DAT_00f3a04c != 0) && (DAT_00e39a54 != 0)) {
    FUN_005d3a70(0xe,DAT_00e80b80);
    DAT_00e39a00 = 1;
  }
  uVar2 = DAT_00e80b7c;
  DAT_00e80b80 = uVar1;
  if ((DAT_00f3a04c != 0) && (DAT_00e39a54 != 0)) {
    FUN_005d3a70(0x17,DAT_00e80b7c);
    DAT_00e39a00 = 1;
  }
  uVar1 = DAT_00e79848;
  DAT_00e80b7c = uVar2;
  if ((DAT_00f3a04c != 0) && (DAT_00e39a54 != 0)) {
    FUN_005d3a70(0xc3,DAT_00e79848);
    DAT_00e39a00 = 1;
  }
  uVar2 = DAT_00e79870;
  DAT_00e79848 = uVar1;
  if ((DAT_00f3a04c != 0) && (DAT_00e39a54 != 0)) {
    FUN_005d3a70(8,DAT_00e79870);
    DAT_00e39a00 = 1;
  }
  DAT_00e79870 = uVar2;
  FUN_00521bf0(&DAT_00a38290);
  FUN_00521cd0(&DAT_00a38358);
  FUN_00524ad0(&DAT_00a38420);
  FUN_00521d40(&DAT_00a38718);
  FUN_005a7a00(&DAT_00e804a4);
  if ((DAT_00f3a04c != 0) && (DAT_00e39a54 != 0)) {
    DAT_00e39a00 = 1;
    FUN_005d3a70(0x1d,DAT_00e80b5c);
  }
  FUN_005a0440(DAT_00e804f8);
  FUN_005a0510(DAT_00e804fc);
  FUN_005a7c20((int)ROUND(_DAT_00e79894) * 0xff | (int)ROUND(_DAT_00e7988c) * 0xff0000 |
               (int)ROUND(_DAT_00e79890) * 0xff00 | (int)ROUND(_DAT_00e79898) * -0x1000000);
  uVar1 = DAT_00e804a0;
  if ((DAT_00f3a04c != 0) && (DAT_00e39a54 != 0)) {
    DAT_00e39a00 = 1;
    FUN_00597e70();
    FUN_005d3a70(0x89,uVar1);
  }
  iVar3 = 0;
  piVar4 = &DAT_00e79ca0;
  do {
    if (*piVar4 != 0) {
      FUN_005a7650(iVar3,piVar4);
      FUN_005a7930(iVar3,(&DAT_00e798a0)[iVar3]);
    }
    piVar4 = piVar4 + 0x1a;
    iVar3 = iVar3 + 1;
  } while ((int)piVar4 < 0xe804a0);
  FUN_0056d380(&local_18,0,0x18);
  local_8 = 0;
  local_4 = 0x3f800000;
  local_10 = DAT_00a3819c - DAT_00a38194;
  local_18 = DAT_00a38194;
  local_c = DAT_00a381a0 - DAT_00a38198;
  local_14 = DAT_00a38198;
  FUN_005a09f0(&local_18);
  FUN_005a0b10(&DAT_00a38194);
  uVar5 = 0;
  if (DAT_00ddb4b4 != 0) {
    puVar7 = &DAT_00e796c8;
    do {
      if ((*puVar7 != uVar5) || (DAT_00e39a54 != 0)) {
        FUN_005d3ab0(uVar5,0xb,uVar5);
        *puVar7 = uVar5;
      }
      uVar5 = uVar5 + 1;
      puVar7 = puVar7 + 6;
    } while (uVar5 < DAT_00ddb4b4);
  }
  FUN_005a0d80(0,0,1,0);
  FUN_005a0d80(0,0,1,1);
  FUN_005b5550();
  DAT_00e39a54 = 0;
  return 0;
}

