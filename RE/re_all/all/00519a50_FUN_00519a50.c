
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00519a50(void)

{
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  undefined4 *puVar7;
  undefined *puVar8;
  undefined8 uVar9;
  double local_38;
  double local_30;
  double local_28;
  undefined1 local_20 [28];
  
  if (DAT_00a387d8 != 1) {
    uVar9 = 0xa3835800a38290;
    puVar8 = &DAT_00a38968;
    FUN_005852e0();
    FUN_005852e0(&DAT_00a389e8,&DAT_00a38358,&DAT_00a38420,puVar8,uVar9);
    FUN_005852e0(&DAT_00a389e8,&DAT_00a389e8,&DAT_00a38718);
    FUN_005852e0(&DAT_00a387e0,&DAT_00a38290,&DAT_00a389e8);
    FUN_00584ff0(&DAT_00a38860,&DAT_00a387e0);
    _DAT_00a38a68 = _DAT_00a38358;
    _DAT_00a38a70 = _DAT_00a38378;
    _DAT_00a38a78 = _DAT_00a38398;
    _DAT_00a38a80 = 0;
    _DAT_00a38a88 = _DAT_00a38360;
    _DAT_00a38a90 = _DAT_00a38380;
    _DAT_00a38a98 = _DAT_00a383a0;
    _DAT_00a38aa0 = 0;
    _DAT_00a38aa8 = _DAT_00a38368;
    _DAT_00a38ab0 = _DAT_00a38388;
    _DAT_00a38ab8 = _DAT_00a383a8;
    _DAT_00a38ac0 = 0;
    _DAT_00a38ae0 = 0;
    _DAT_00a38ad8 = 0;
    _DAT_00a38ad0 = 0;
    _DAT_00a38ac8 = 0;
    FUN_00584ff0(&DAT_00a38ae8,&DAT_00a38a68);
    DAT_00a388a0 = 0;
    DAT_00a387d8 = 1;
    _DAT_00a38ca8 = 0;
    if ((DAT_00a38194 != DAT_00a3819c) && (DAT_00a38198 != DAT_00a381a0)) {
      puVar7 = (undefined4 *)FUN_00516350(local_20,(double)DAT_00a381a4,(double)DAT_00a381a8,0);
      _DAT_00a38b28 = *puVar7;
      _DAT_00a38b2c = puVar7[1];
      _DAT_00a38b30 = puVar7[2];
      _DAT_00a38b34 = puVar7[3];
      _DAT_00a38b38 = puVar7[4];
      _DAT_00a38b3c = puVar7[5];
      puVar7 = (undefined4 *)FUN_00516350(local_20,(double)DAT_00a381ac,(double)DAT_00a381a8,0);
      _DAT_00a38b40 = *puVar7;
      _DAT_00a38b44 = puVar7[1];
      _DAT_00a38b48 = puVar7[2];
      _DAT_00a38b4c = puVar7[3];
      _DAT_00a38b50 = puVar7[4];
      _DAT_00a38b54 = puVar7[5];
      puVar7 = (undefined4 *)FUN_00516350(local_20,(double)DAT_00a381a4,(double)DAT_00a381b0,0);
      _DAT_00a38b58 = *puVar7;
      _DAT_00a38b5c = puVar7[1];
      _DAT_00a38b60 = puVar7[2];
      _DAT_00a38b64 = puVar7[3];
      _DAT_00a38b68 = puVar7[4];
      _DAT_00a38b6c = puVar7[5];
      puVar7 = (undefined4 *)FUN_00516350(local_20,(double)DAT_00a381ac,(double)DAT_00a381b0,0);
      _DAT_00a38b70 = *puVar7;
      _DAT_00a38b74 = puVar7[1];
      _DAT_00a38b78 = puVar7[2];
      _DAT_00a38b7c = puVar7[3];
      _DAT_00a38b80 = puVar7[4];
      _DAT_00a38b84 = puVar7[5];
      puVar7 = (undefined4 *)
               FUN_00516350(local_20,(double)DAT_00a381a4,(double)DAT_00a381a8,0x3ff0000000000000);
      _DAT_00a38b88 = *puVar7;
      _DAT_00a38b8c = puVar7[1];
      _DAT_00a38b90 = puVar7[2];
      _DAT_00a38b94 = puVar7[3];
      _DAT_00a38b98 = puVar7[4];
      _DAT_00a38b9c = puVar7[5];
      puVar7 = (undefined4 *)
               FUN_00516350(local_20,(double)DAT_00a381ac,(double)DAT_00a381a8,0x3ff0000000000000);
      _DAT_00a38ba0 = *puVar7;
      _DAT_00a38ba4 = puVar7[1];
      _DAT_00a38ba8 = puVar7[2];
      _DAT_00a38bac = puVar7[3];
      _DAT_00a38bb0 = puVar7[4];
      _DAT_00a38bb4 = puVar7[5];
      puVar7 = (undefined4 *)
               FUN_00516350(local_20,(double)DAT_00a381a4,(double)DAT_00a381b0,0x3ff0000000000000);
      _DAT_00a38bb8 = *puVar7;
      _DAT_00a38bbc = puVar7[1];
      _DAT_00a38bc0 = puVar7[2];
      _DAT_00a38bc4 = puVar7[3];
      _DAT_00a38bc8 = puVar7[4];
      _DAT_00a38bcc = puVar7[5];
      puVar7 = (undefined4 *)
               FUN_00516350(local_20,(double)DAT_00a381ac,(double)DAT_00a381b0,0x3ff0000000000000);
      _DAT_00a38bd0 = *puVar7;
      dVar1 = (double)CONCAT44(_DAT_00a38b5c,_DAT_00a38b58) -
              (double)CONCAT44(_DAT_00a38b2c,_DAT_00a38b28);
      _DAT_00a38bd4 = puVar7[1];
      dVar5 = (double)CONCAT44(_DAT_00a38b64,_DAT_00a38b60) -
              (double)CONCAT44(_DAT_00a38b34,_DAT_00a38b30);
      _DAT_00a38bd8 = puVar7[2];
      _DAT_00a38bdc = puVar7[3];
      dVar3 = (double)CONCAT44(_DAT_00a38b6c,_DAT_00a38b68) -
              (double)CONCAT44(_DAT_00a38b3c,_DAT_00a38b38);
      _DAT_00a38be0 = puVar7[4];
      dVar2 = (double)CONCAT44(_DAT_00a38b8c,_DAT_00a38b88) -
              (double)CONCAT44(_DAT_00a38b2c,_DAT_00a38b28);
      _DAT_00a38be4 = puVar7[5];
      dVar6 = (double)CONCAT44(_DAT_00a38b94,_DAT_00a38b90) -
              (double)CONCAT44(_DAT_00a38b34,_DAT_00a38b30);
      dVar4 = (double)CONCAT44(_DAT_00a38b9c,_DAT_00a38b98) -
              (double)CONCAT44(_DAT_00a38b3c,_DAT_00a38b38);
      local_38 = dVar6 * dVar3 - dVar4 * dVar5;
      local_30 = dVar4 * dVar1 - dVar3 * dVar2;
      local_28 = dVar5 * dVar2 - dVar6 * dVar1;
      FUN_00584ef0(&DAT_00a38be8,&DAT_00a38b28,&local_38);
      dVar1 = (double)CONCAT44(_DAT_00a38ba4,_DAT_00a38ba0) -
              (double)CONCAT44(_DAT_00a38b44,_DAT_00a38b40);
      dVar5 = (double)CONCAT44(_DAT_00a38bac,_DAT_00a38ba8) -
              (double)CONCAT44(_DAT_00a38b4c,_DAT_00a38b48);
      dVar3 = (double)CONCAT44(_DAT_00a38bb4,_DAT_00a38bb0) -
              (double)CONCAT44(_DAT_00a38b54,_DAT_00a38b50);
      dVar2 = (double)CONCAT44(_DAT_00a38b74,_DAT_00a38b70) -
              (double)CONCAT44(_DAT_00a38b44,_DAT_00a38b40);
      dVar6 = (double)CONCAT44(_DAT_00a38b7c,_DAT_00a38b78) -
              (double)CONCAT44(_DAT_00a38b4c,_DAT_00a38b48);
      dVar4 = (double)CONCAT44(_DAT_00a38b84,_DAT_00a38b80) -
              (double)CONCAT44(_DAT_00a38b54,_DAT_00a38b50);
      local_38 = dVar6 * dVar3 - dVar4 * dVar5;
      local_30 = dVar4 * dVar1 - dVar3 * dVar2;
      local_28 = dVar5 * dVar2 - dVar6 * dVar1;
      FUN_00584ef0(&DAT_00a38c08,&DAT_00a38b40,&local_38);
      dVar1 = (double)CONCAT44(_DAT_00a38b74,_DAT_00a38b70) -
              (double)CONCAT44(_DAT_00a38b5c,_DAT_00a38b58);
      dVar5 = (double)CONCAT44(_DAT_00a38b7c,_DAT_00a38b78) -
              (double)CONCAT44(_DAT_00a38b64,_DAT_00a38b60);
      dVar3 = (double)CONCAT44(_DAT_00a38b84,_DAT_00a38b80) -
              (double)CONCAT44(_DAT_00a38b6c,_DAT_00a38b68);
      dVar2 = (double)CONCAT44(_DAT_00a38bbc,_DAT_00a38bb8) -
              (double)CONCAT44(_DAT_00a38b5c,_DAT_00a38b58);
      dVar6 = (double)CONCAT44(_DAT_00a38bc4,_DAT_00a38bc0) -
              (double)CONCAT44(_DAT_00a38b64,_DAT_00a38b60);
      dVar4 = (double)CONCAT44(_DAT_00a38bcc,_DAT_00a38bc8) -
              (double)CONCAT44(_DAT_00a38b6c,_DAT_00a38b68);
      local_38 = dVar6 * dVar3 - dVar4 * dVar5;
      local_30 = dVar4 * dVar1 - dVar3 * dVar2;
      local_28 = dVar5 * dVar2 - dVar6 * dVar1;
      FUN_00584ef0(&DAT_00a38c28,&DAT_00a38b58,&local_38);
      dVar1 = (double)CONCAT44(_DAT_00a38b8c,_DAT_00a38b88) -
              (double)CONCAT44(_DAT_00a38b2c,_DAT_00a38b28);
      dVar5 = (double)CONCAT44(_DAT_00a38b94,_DAT_00a38b90) -
              (double)CONCAT44(_DAT_00a38b34,_DAT_00a38b30);
      dVar3 = (double)CONCAT44(_DAT_00a38b9c,_DAT_00a38b98) -
              (double)CONCAT44(_DAT_00a38b3c,_DAT_00a38b38);
      dVar2 = (double)CONCAT44(_DAT_00a38b44,_DAT_00a38b40) -
              (double)CONCAT44(_DAT_00a38b2c,_DAT_00a38b28);
      dVar6 = (double)CONCAT44(_DAT_00a38b4c,_DAT_00a38b48) -
              (double)CONCAT44(_DAT_00a38b34,_DAT_00a38b30);
      dVar4 = (double)CONCAT44(_DAT_00a38b54,_DAT_00a38b50) -
              (double)CONCAT44(_DAT_00a38b3c,_DAT_00a38b38);
      uVar9 = CONCAT44(&local_38,&DAT_00a38b28);
      local_38 = dVar6 * dVar3 - dVar4 * dVar5;
      local_30 = dVar4 * dVar1 - dVar3 * dVar2;
      local_28 = dVar5 * dVar2 - dVar6 * dVar1;
      puVar8 = &DAT_00a38c48;
      FUN_00584ef0();
      dVar1 = (double)CONCAT44(_DAT_00a38b44,_DAT_00a38b40) -
              (double)CONCAT44(_DAT_00a38b2c,_DAT_00a38b28);
      dVar5 = (double)CONCAT44(_DAT_00a38b4c,_DAT_00a38b48) -
              (double)CONCAT44(_DAT_00a38b34,_DAT_00a38b30);
      dVar3 = (double)CONCAT44(_DAT_00a38b54,_DAT_00a38b50) -
              (double)CONCAT44(_DAT_00a38b3c,_DAT_00a38b38);
      dVar2 = (double)CONCAT44(_DAT_00a38b5c,_DAT_00a38b58) -
              (double)CONCAT44(_DAT_00a38b2c,_DAT_00a38b28);
      dVar6 = (double)CONCAT44(_DAT_00a38b64,_DAT_00a38b60) -
              (double)CONCAT44(_DAT_00a38b34,_DAT_00a38b30);
      dVar4 = (double)CONCAT44(_DAT_00a38b6c,_DAT_00a38b68) -
              (double)CONCAT44(_DAT_00a38b3c,_DAT_00a38b38);
      local_38 = dVar6 * dVar3 - dVar4 * dVar5;
      local_30 = dVar4 * dVar1 - dVar3 * dVar2;
      local_28 = dVar5 * dVar2 - dVar6 * dVar1;
      FUN_00584ef0(&DAT_00a38c68,&DAT_00a38b28,&local_38,puVar8,uVar9);
      dVar1 = (double)CONCAT44(_DAT_00a38bbc,_DAT_00a38bb8) -
              (double)CONCAT44(_DAT_00a38b8c,_DAT_00a38b88);
      dVar5 = (double)CONCAT44(_DAT_00a38bc4,_DAT_00a38bc0) -
              (double)CONCAT44(_DAT_00a38b94,_DAT_00a38b90);
      dVar3 = (double)CONCAT44(_DAT_00a38bcc,_DAT_00a38bc8) -
              (double)CONCAT44(_DAT_00a38b9c,_DAT_00a38b98);
      dVar2 = (double)CONCAT44(_DAT_00a38ba4,_DAT_00a38ba0) -
              (double)CONCAT44(_DAT_00a38b8c,_DAT_00a38b88);
      dVar6 = (double)CONCAT44(_DAT_00a38bac,_DAT_00a38ba8) -
              (double)CONCAT44(_DAT_00a38b94,_DAT_00a38b90);
      dVar4 = (double)CONCAT44(_DAT_00a38bb4,_DAT_00a38bb0) -
              (double)CONCAT44(_DAT_00a38b9c,_DAT_00a38b98);
      local_38 = dVar6 * dVar3 - dVar4 * dVar5;
      local_30 = dVar4 * dVar1 - dVar3 * dVar2;
      local_28 = dVar5 * dVar2 - dVar6 * dVar1;
      FUN_00584ef0(&DAT_00a38c88,&DAT_00a38b88,&local_38);
      return;
    }
    uVar9 = 0xc000000000;
    puVar8 = &DAT_00a38b28;
    FUN_0056d380();
    FUN_0056d380(&DAT_00a38be8,0,0xc0,puVar8,uVar9);
  }
  return;
}

