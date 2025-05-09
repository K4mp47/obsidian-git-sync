PGDMP                         {            postgres    15.2    15.1     '           0    0    ENCODING    ENCODING        SET client_encoding = 'UTF8';
                      false            (           0    0 
   STDSTRINGS 
   STDSTRINGS     (   SET standard_conforming_strings = 'on';
                      false            )           0    0 
   SEARCHPATH 
   SEARCHPATH     8   SELECT pg_catalog.set_config('search_path', '', false);
                      false            *           1262    5    postgres    DATABASE     j   CREATE DATABASE postgres WITH TEMPLATE = template0 ENCODING = 'UTF8' LOCALE_PROVIDER = libc LOCALE = 'C';
    DROP DATABASE postgres;
                postgres    false            +           0    0    DATABASE postgres    COMMENT     N   COMMENT ON DATABASE postgres IS 'default administrative connection database';
                   postgres    false    3626                        2615    16988    lab    SCHEMA        CREATE SCHEMA lab;
    DROP SCHEMA lab;
                postgres    false            �            1259    17004    laptop    TABLE     �   CREATE TABLE lab.laptop (
    model integer NOT NULL,
    speed real,
    ram smallint,
    hd smallint,
    screen real,
    price real
);
    DROP TABLE lab.laptop;
       lab         heap    postgres    false    7            �            1259    16994    pc    TABLE     w   CREATE TABLE lab.pc (
    model integer NOT NULL,
    speed real,
    ram smallint,
    hd smallint,
    price real
);
    DROP TABLE lab.pc;
       lab         heap    postgres    false    7            �            1259    17014    printer    TABLE     |   CREATE TABLE lab.printer (
    model integer NOT NULL,
    color boolean,
    type character varying(10),
    price real
);
    DROP TABLE lab.printer;
       lab         heap    postgres    false    7            �            1259    16989    product    TABLE     z   CREATE TABLE lab.product (
    maker character varying(30),
    model integer NOT NULL,
    type character varying(30)
);
    DROP TABLE lab.product;
       lab         heap    postgres    false    7            #          0    17004    laptop 
   TABLE DATA           C   COPY lab.laptop (model, speed, ram, hd, screen, price) FROM stdin;
    lab          postgres    false    222   f       "          0    16994    pc 
   TABLE DATA           7   COPY lab.pc (model, speed, ram, hd, price) FROM stdin;
    lab          postgres    false    221   �       $          0    17014    printer 
   TABLE DATA           9   COPY lab.printer (model, color, type, price) FROM stdin;
    lab          postgres    false    223   d       !          0    16989    product 
   TABLE DATA           2   COPY lab.product (maker, model, type) FROM stdin;
    lab          postgres    false    220   �       �           2606    17008    laptop laptop_pkey 
   CONSTRAINT     P   ALTER TABLE ONLY lab.laptop
    ADD CONSTRAINT laptop_pkey PRIMARY KEY (model);
 9   ALTER TABLE ONLY lab.laptop DROP CONSTRAINT laptop_pkey;
       lab            postgres    false    222            �           2606    16998 
   pc pc_pkey 
   CONSTRAINT     H   ALTER TABLE ONLY lab.pc
    ADD CONSTRAINT pc_pkey PRIMARY KEY (model);
 1   ALTER TABLE ONLY lab.pc DROP CONSTRAINT pc_pkey;
       lab            postgres    false    221            �           2606    17018    printer printer_pkey 
   CONSTRAINT     R   ALTER TABLE ONLY lab.printer
    ADD CONSTRAINT printer_pkey PRIMARY KEY (model);
 ;   ALTER TABLE ONLY lab.printer DROP CONSTRAINT printer_pkey;
       lab            postgres    false    223            �           2606    16993    product product_pkey 
   CONSTRAINT     R   ALTER TABLE ONLY lab.product
    ADD CONSTRAINT product_pkey PRIMARY KEY (model);
 ;   ALTER TABLE ONLY lab.product DROP CONSTRAINT product_pkey;
       lab            postgres    false    220            �           2606    17009    laptop laptop_model_fkey    FK CONSTRAINT     w   ALTER TABLE ONLY lab.laptop
    ADD CONSTRAINT laptop_model_fkey FOREIGN KEY (model) REFERENCES    lab.product(model);
 ?   ALTER TABLE ONLY lab.laptop DROP CONSTRAINT laptop_model_fkey;
       lab          postgres    false    222            �           2606    16999    pc pc_model_fkey    FK CONSTRAINT     o   ALTER TABLE ONLY lab.pc
    ADD CONSTRAINT pc_model_fkey FOREIGN KEY (model) REFERENCES    lab.product(model);
 7   ALTER TABLE ONLY lab.pc DROP CONSTRAINT pc_model_fkey;
       lab          postgres    false    221            �           2606    17019    printer printer_model_fkey    FK CONSTRAINT     y   ALTER TABLE ONLY lab.printer
    ADD CONSTRAINT printer_model_fkey FOREIGN KEY (model) REFERENCES    lab.product(model);
 A   ALTER TABLE ONLY lab.printer DROP CONSTRAINT printer_model_fkey;
       lab          postgres    false    223            #   i   x�M��C1C�f��a��?GI�/}H<��f� l¡�$G��\D�X�}x%G��92.�	�ޤL�c��ʋ�v���j,�x�^*(�s=u��y
�g��RF      "   u   x�M�Q
1C��0%��ڻ��ϱ�a`E!		H�.��(m�K�	�F���<"���XOJ>�
nW:(; �lJ�n���z�7�r�}��q��k\��R��@�dv��۩�w�i�o��'�!�      $   ]   x�M�+�0EQ�,&��Y��S*讀��3�]Q8a��X@���Y�N�X�E���$B{��<��E�5�2�0xƤ&�ܷ��?�� D� F�      !   �   x�e��� D��1X�±�&��hҫ��Aӈ�@���֪�v��첥=��d[\�D@��V� �<	k�
J���gD9���*��H�L���}:��U&�|L�U�������S��do?>����� �Ϩ�Zg����?���ĥ�M(���u������b��<�;��Yoz$a�	���ɳ���� �9j�     