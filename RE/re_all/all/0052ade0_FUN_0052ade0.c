
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0052ade0(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  uVar3 = DAT_00a3818c;
  uVar2 = DAT_00a38188;
  uVar1 = DAT_00a38184;
  local_4 = DAT_00a38190;
  local_18 = DAT_00a380c4;
  FUN_0056d380(&DAT_00a37fb0,0,0xe30);
  FUN_0056d380(&DAT_00a3d268,0,0xf8);
  DAT_00a380c4 = local_18;
  DAT_00a38190 = local_4;
  piVar4 = &DAT_00a38020;
  DAT_00a38184 = uVar1;
  DAT_00a38188 = uVar2;
  DAT_00a3818c = uVar3;
  do {
    if (piVar4[-0x10] == 0) {
      piVar4[-0x10] = 3;
    }
    if (*piVar4 == 0) {
      *piVar4 = 3;
    }
    if (piVar4[0x10] == 0) {
      piVar4[0x10] = 3;
    }
    piVar4 = piVar4 + 1;
  } while ((int)piVar4 < 0xa38060);
  DAT_00a380b8 = _DAT_00838a98;
  DAT_00a380d4 = 0xffffffff;
  DAT_00a37fb0 = 0;
  DAT_00a37fb4 = 0;
  DAT_00a37fc0 = 0;
  DAT_00a37fc4 = 0;
  DAT_00a3d258 = 1;
  DAT_00a3d360 = 1;
  DAT_00a37fb8 = 4;
  DAT_00a37fc8 = 4;
  DAT_00a37f0c = 1;
  DAT_00a52a58 = 1;
  DAT_00a380bc = 0;
  DAT_00a380c0 = 1;
  DAT_00a37fd8 = 3;
  DAT_00a380cc = 0;
  DAT_00a380ec = 0xffffffff;
  if (((DAT_00a38116 != -1) || (DAT_00a38115 != -1)) || (DAT_00a38114 != -1)) {
    _DAT_00a38114 = CONCAT13(DAT_00a38116_1,0xff0000);
    _DAT_00a38114 = CONCAT22(_DAT_00a38116,0xffff);
    if (DAT_00a37d78 == 0) {
      FUN_00581200(_DAT_00a38114);
    }
    else {
      FUN_00567b70(0xff,0xff,0xff);
    }
  }
  if (DAT_00a380a4 != 3) {
    FUN_00568ca0(0);
    if (DAT_00dda46c != 0) {
      FUN_00584d70();
    }
    DAT_00a380a4 = 3;
    if (DAT_00a37d78 != 0) {
      FUN_00567c70(3);
    }
  }
  if (DAT_00a380a8 != -1) {
    FUN_00568ca0(0);
    if (DAT_00dda46c != 0) {
      FUN_00584d70();
    }
    DAT_00a380a8 = -1;
    if (DAT_00a37d78 != 0) {
      FUN_00567c90(0xffffffff);
    }
  }
  FUN_00516450(0,_DAT_007d5920);
  DAT_00a37f00 = 0;
  DAT_00ca39f0 = 1;
  DAT_00ca39f4 = 0;
  DAT_00a38120 = 0xfffffffe;
  DAT_00a38140 = 0;
  DAT_00a38160 = 0;
  FUN_0052a4a0(0xfffffffc);
  FUN_00515880(DAT_00a38120,&local_14,&local_18);
  FUN_005217e0(0,0,local_14,local_18);
  local_10 = 0x3f800000;
  local_c = _DAT_007d5340;
  local_8 = 0x3f800000;
  DAT_00a3d260 = FUN_00522230(0x3f800000,_DAT_007d5340,0x3f800000);
  FUN_00585080(&DAT_00a381c8);
  FUN_00585060(&DAT_00a38248);
  FUN_00585080(&DAT_00a38290);
  FUN_00585060(&DAT_00a38310);
  FUN_00585080(&DAT_00a38358);
  FUN_00585060(&DAT_00a383d8);
  FUN_00585080(&DAT_00a38420);
  FUN_00585060(&DAT_00a384a0);
  FUN_00585080(&DAT_00a38598);
  FUN_00585060(&DAT_00a38618);
  FUN_00585080(&DAT_00a38658);
  FUN_00585060(&DAT_00a386d8);
  FUN_00585080(&DAT_00a38718);
  FUN_00585060(&DAT_00a38798);
  FUN_00585080(&DAT_00a387e0);
  FUN_00585060(&DAT_00a38860);
  FUN_00585080(&DAT_00a388a8);
  FUN_00585060(&DAT_00a38928);
  FUN_00585080(&DAT_00a38968);
  FUN_00585080(&DAT_00a389e8);
  FUN_00585080(&DAT_00a38a68);
  FUN_00585060(&DAT_00a38ae8);
  FUN_00585080(&DAT_00a38cb0);
  FUN_00585060(&DAT_00a38d38);
  _DAT_00a384e8 = _DAT_0081ec08;
  DAT_00a384e0 = 0;
  _DAT_00a384f0 = _DAT_007d5918;
  _DAT_00a384f8 = 0x3ff0000000000000;
  _DAT_00a38500 = _DAT_007d5900;
  _DAT_00a38508 = 0x3ff0000000000000;
  FUN_00585080(&DAT_00a38510);
  DAT_00a38de4 = 1;
  puVar5 = (undefined4 *)
           FUN_00543f20(&local_10,_DAT_007d5914,_DAT_007d5914,_DAT_007d5914,0x3f800000);
  _DAT_00a38de8 = *puVar5;
  _DAT_00a38dec = puVar5[1];
  _DAT_00a38df0 = puVar5[2];
  _DAT_00a38df4 = puVar5[3];
  puVar5 = (undefined4 *)FUN_00543f20(&local_10,_DAT_007d5914,_DAT_007d5914,_DAT_007d5914,0);
  _DAT_00a38e08 = *puVar5;
  _DAT_00a38e0c = puVar5[1];
  _DAT_00a38e10 = puVar5[2];
  _DAT_00a38e14 = puVar5[3];
  puVar5 = (undefined4 *)FUN_00543f20(&local_10,0,0,0,0);
  _DAT_00a38df8 = *puVar5;
  _DAT_00a38dfc = puVar5[1];
  _DAT_00a38e00 = puVar5[2];
  _DAT_00a38e04 = puVar5[3];
  puVar5 = (undefined4 *)FUN_00543f20(&local_10,0,0,0,0);
  _DAT_00a38e18 = *puVar5;
  _DAT_00a38e1c = puVar5[1];
  _DAT_00a38e20 = puVar5[2];
  _DAT_00a38e28 = _DAT_007d5910;
  DAT_00a3d360 = 1;
  _DAT_00a381bc = 0x3f800000;
  _DAT_00a38e24 = puVar5[3];
  return 0;
}

