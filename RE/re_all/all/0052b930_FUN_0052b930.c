
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0052b930(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  
  if (DAT_00a3810c == 0) {
    return 0xffffffff;
  }
  if ((((DAT_00cc79c0 == 0) || ((int)DAT_00a38110 < 0)) ||
      ((DAT_00a38110 & 0x7c000000) != DAT_00cc79e8)) ||
     (((DAT_00cc79f0 <= (int)(DAT_00a38110 & 0xffff) ||
       (piVar1 = *(int **)(DAT_00cc79c4 + (DAT_00a38110 & 0xffff) * 4), piVar1 == (int *)0x0)) ||
      ((*piVar1 * 0x10000 != (DAT_00a38110 & 0x3ff0000) || (piVar1[4] != 0)))))) {
    DAT_00a3810c = 0;
  }
  else if (piVar1[0x4a] != 0) {
    piVar1[0x4a] = 0;
    DAT_00a3810c = 0;
    DAT_00a38110 = 0;
    iVar3 = 0;
    piVar2 = piVar1 + 0x99;
    do {
      FUN_0052aa40(iVar3,piVar2[-8],*piVar2,piVar2[8]);
      iVar3 = iVar3 + 1;
      piVar2 = piVar2 + 1;
    } while (iVar3 < 8);
    FUN_0057b060();
    FUN_00516400(piVar1[0xaa]);
    _DAT_00a3d268 = piVar1[0xac];
    _DAT_00a3d26c = piVar1[0xad];
    _DAT_00a3d270 = piVar1[0xae];
    _DAT_00a3d274 = piVar1[0xaf];
    _DAT_00a3d278 = piVar1[0xb0];
    _DAT_00a3d27c = piVar1[0xb1];
    _DAT_00a3d280 = piVar1[0xb2];
    _DAT_00a3d284 = piVar1[0xb3];
    _DAT_00a3d288 = piVar1[0xb4];
    _DAT_00a3d28c = piVar1[0xb5];
    _DAT_00a3d290 = piVar1[0xb6];
    _DAT_00a3d294 = piVar1[0xb7];
    _DAT_00a3d298 = piVar1[0xb8];
    _DAT_00a3d29c = piVar1[0xb9];
    _DAT_00a3d2a0 = piVar1[0xba];
    _DAT_00a3d2a4 = piVar1[0xbb];
    _DAT_00a3d2a8 = piVar1[0xbc];
    _DAT_00a3d2ac = piVar1[0xbd];
    _DAT_00a3d2b0 = *(undefined8 *)(piVar1 + 0xbe);
    _DAT_00a3d2b8 = *(undefined8 *)(piVar1 + 0xc0);
    _DAT_00a3d2c0 = *(undefined8 *)(piVar1 + 0xc2);
    piVar2 = piVar1 + 0xc4;
    piVar4 = &DAT_00a3d2c8;
    for (iVar3 = 0x20; iVar3 != 0; iVar3 = iVar3 + -1) {
      *piVar4 = *piVar2;
      piVar2 = piVar2 + 1;
      piVar4 = piVar4 + 1;
    }
    FUN_00521cd0();
    FUN_005221c0(*(undefined8 *)(piVar1 + 0xe4),*(undefined8 *)(piVar1 + 0xe6));
    DAT_00a384e0 = piVar1[0xe8];
    _DAT_00a384e8 = *(undefined8 *)(piVar1 + 0xea);
    _DAT_00a384f0 = *(undefined8 *)(piVar1 + 0xec);
    _DAT_00a384f8 = *(undefined8 *)(piVar1 + 0xee);
    _DAT_00a38500 = *(undefined8 *)(piVar1 + 0xf0);
    _DAT_00a38508 = *(undefined8 *)(piVar1 + 0xf2);
    piVar2 = piVar1 + 0xf4;
    piVar4 = &DAT_00a38510;
    for (iVar3 = 0x20; iVar3 != 0; iVar3 = iVar3 + -1) {
      *piVar4 = *piVar2;
      piVar2 = piVar2 + 1;
      piVar4 = piVar4 + 1;
    }
    FUN_00524ad0(&DAT_00a38510);
    FUN_00568be0(piVar1);
    if (0 < piVar1[0x7c]) {
      FUN_00594b10(piVar1[1],1,8,piVar1[0x7c]);
    }
    return 0;
  }
  return 0xffffffff;
}

