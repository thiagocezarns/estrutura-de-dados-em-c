require 'faker'

File.open("alunos.txt", "w") do |file|
  i = 0
  while(i < 1_000_010) do
    file.write("#{Faker::Name.first_name} #{Faker::Number.number(digits: 7)}\n")
    i += 1
  end
end
