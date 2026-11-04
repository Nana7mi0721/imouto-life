
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005857a0(double *param_1,undefined4 *param_2)

{
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  double dVar12;
  double dVar13;
  int iVar14;
  double *pdVar15;
  double local_160;
  double local_158;
  double local_150;
  double local_148;
  double local_140;
  double local_138;
  double local_130;
  double local_128;
  double local_120;
  double local_118;
  double local_110;
  double local_108;
  double local_100;
  double local_f8;
  double local_f0;
  double local_e8;
  
  pdVar15 = &local_160;
  for (iVar14 = 0x20; iVar14 != 0; iVar14 = iVar14 + -1) {
    *(undefined4 *)pdVar15 = *param_2;
    param_2 = param_2 + 1;
    pdVar15 = (double *)((int)pdVar15 + 4);
  }
  dVar11 = local_130 * local_160;
  dVar9 = local_138 * local_160;
  dVar10 = local_128 * local_160;
  dVar4 = local_140 * local_158;
  dVar1 = local_158 * local_130;
  dVar5 = local_158 * local_128;
  dVar12 = local_150 * local_140;
  dVar3 = local_150 * local_138;
  dVar7 = local_150 * local_128;
  dVar8 = local_148 * local_140;
  dVar6 = local_148 * local_138;
  dVar2 = local_148 * local_130;
  dVar13 = ((((((((((((dVar2 * local_118 * local_100 +
                      dVar6 * local_120 * local_f0 +
                      dVar8 * local_110 * local_f8 +
                      dVar7 * local_120 * local_f8 +
                      dVar3 * local_108 * local_100 +
                      dVar12 * local_118 * local_e8 +
                      dVar1 * local_120 * local_e8 +
                      dVar4 * local_108 * local_f0 +
                      dVar11 * local_108 * local_f8 + dVar9 * local_110 * local_e8 +
                      dVar10 * local_118 * local_f0 + dVar5 * local_110 * local_100) -
                     dVar9 * local_108 * local_f0) - dVar11 * local_118 * local_e8) -
                   dVar10 * local_110 * local_f8) - dVar4 * local_110 * local_e8) -
                 dVar1 * local_108 * local_100) - dVar5 * local_120 * local_f0) -
               dVar12 * local_108 * local_f8) - dVar3 * local_120 * local_e8) -
             dVar7 * local_118 * local_100) - dVar8 * local_118 * local_f0) -
           dVar6 * local_110 * local_100) - local_120 * dVar2 * local_f8;
  if ((dVar13 < _DAT_007d9b80) && (_DAT_007d6140 < dVar13)) {
    return 0xffffffff;
  }
  *param_1 = ((((local_118 * local_128 * local_f0 +
                local_110 * local_138 * local_e8 + local_108 * local_130 * local_f8) -
               local_108 * local_138 * local_f0) - local_e8 * local_118 * local_130) -
             local_f8 * local_128 * local_110) / dVar13;
  param_1[1] = ((((local_148 * local_110 * local_f8 +
                  local_150 * local_118 * local_e8 + local_158 * local_108 * local_f0) -
                 local_110 * local_158 * local_e8) - local_150 * local_108 * local_f8) -
               local_148 * local_118 * local_f0) / dVar13;
  param_1[2] = ((((dVar6 * local_f0 + dVar1 * local_e8 + dVar7 * local_f8) - dVar5 * local_f0) -
                dVar3 * local_e8) - dVar2 * local_f8) / dVar13;
  param_1[3] = ((((dVar3 * local_108 + dVar5 * local_110 + dVar2 * local_118) - dVar1 * local_108) -
                dVar7 * local_118) - dVar6 * local_110) / dVar13;
  param_1[4] = ((((local_100 * local_128 * local_110 +
                  local_120 * local_130 * local_e8 + local_140 * local_108 * local_f0) -
                 local_140 * local_110 * local_e8) - local_108 * local_130 * local_100) -
               local_120 * local_128 * local_f0) / dVar13;
  param_1[5] = ((((local_148 * local_120 * local_f0 +
                  local_150 * local_108 * local_100 + local_110 * local_160 * local_e8) -
                 local_108 * local_160 * local_f0) - local_150 * local_120 * local_e8) -
               local_148 * local_110 * local_100) / dVar13;
  param_1[6] = ((((dVar2 * local_100 + dVar10 * local_f0 + dVar12 * local_e8) - dVar11 * local_e8) -
                dVar7 * local_100) - dVar8 * local_f0) / dVar13;
  param_1[7] = ((((dVar7 * local_120 + dVar11 * local_108 + dVar8 * local_110) - dVar10 * local_110)
                - dVar12 * local_108) - local_120 * dVar2) / dVar13;
  param_1[8] = ((((local_120 * local_128 * local_f8 +
                  local_108 * local_138 * local_100 + local_140 * local_118 * local_e8) -
                 local_140 * local_108 * local_f8) - local_120 * local_138 * local_e8) -
               local_118 * local_128 * local_100) / dVar13;
  param_1[9] = ((((local_148 * local_118 * local_100 +
                  local_108 * local_160 * local_f8 + local_120 * local_158 * local_e8) -
                 local_118 * local_160 * local_e8) - local_158 * local_108 * local_100) -
               local_148 * local_120 * local_f8) / dVar13;
  param_1[10] = ((((dVar8 * local_f8 + dVar9 * local_e8 + dVar5 * local_100) - dVar10 * local_f8) -
                 dVar4 * local_e8) - dVar6 * local_100) / dVar13;
  param_1[0xb] = ((((dVar4 * local_108 + dVar10 * local_118 + dVar6 * local_120) - dVar9 * local_108
                   ) - dVar5 * local_120) - dVar8 * local_118) / dVar13;
  param_1[0xc] = ((((local_100 * local_118 * local_130 +
                    local_140 * local_110 * local_f8 + local_120 * local_138 * local_f0) -
                   local_140 * local_118 * local_f0) - local_110 * local_138 * local_100) -
                 local_120 * local_130 * local_f8) / dVar13;
  param_1[0xd] = ((((local_150 * local_120 * local_f8 +
                    local_110 * local_158 * local_100 + local_118 * local_160 * local_f0) -
                   local_110 * local_160 * local_f8) - local_120 * local_158 * local_f0) -
                 local_150 * local_118 * local_100) / dVar13;
  param_1[0xe] = ((((dVar3 * local_100 + dVar11 * local_f8 + dVar4 * local_f0) - dVar9 * local_f0) -
                  dVar1 * local_100) - local_f8 * dVar12) / dVar13;
  param_1[0xf] = ((((dVar1 * local_120 + dVar9 * local_110 + dVar12 * local_118) -
                   dVar11 * local_118) - dVar4 * local_110) - dVar3 * local_120) / dVar13;
  return 0;
}

